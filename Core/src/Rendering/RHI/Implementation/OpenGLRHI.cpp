//
// Created by ringo on 2026-02-22.
//

#include "Rendering/RHI/Implementation/OpenGLRHI.h"

#include <glad/gl.h>

namespace rngo
{
    void OpenGLRHI::SetViewportSize(const int width, const int height)
    {
        glViewport(0, 0, width, height);
    }

    void OpenGLRHI::EnableFeatures(const RenderFeatureBit features)
    {
        if ((RenderFeatureBit::DepthTesting & features) != RenderFeatureBit::None)
        {
            glEnable(GL_DEPTH_TEST);
        }

        if ((RenderFeatureBit::Blending & features) != RenderFeatureBit::None)
        {
            glEnable(GL_BLEND);
        }

        if ((RenderFeatureBit::BackFaceCulling & features) != RenderFeatureBit::None)
        {
            glEnable(GL_CULL_FACE);
        }
    }

    void OpenGLRHI::DisableFeatures(const RenderFeatureBit features)
    {
        if ((RenderFeatureBit::DepthTesting & features) != RenderFeatureBit::None)
        {
            glDisable(GL_DEPTH_TEST);
        }

        if ((RenderFeatureBit::Blending & features) != RenderFeatureBit::None)
        {
            glDisable(GL_BLEND);
        }

        if ((RenderFeatureBit::BackFaceCulling & features) != RenderFeatureBit::None)
        {
            glDisable(GL_CULL_FACE);
        }
    }

    void OpenGLRHI::SetClearColor(const std::span<const float, 4> color)
    {
        glClearColor(color[0], color[1], color[2], color[3]);
    }

    void OpenGLRHI::ClearTarget(const ClearTargetBit clearTarget)
    {
        if ((ClearTargetBit::Color & clearTarget) != ClearTargetBit::None)
        {
            glClear(GL_COLOR_BUFFER_BIT);
        }
        if ((ClearTargetBit::Depth & clearTarget) != ClearTargetBit::None)
        {
            glClear(GL_DEPTH_BUFFER_BIT);
        }
        if ((ClearTargetBit::Stencil & clearTarget) != ClearTargetBit::None)
        {
            glClear(GL_STENCIL_BUFFER_BIT);
        }
    }

    void OpenGLRHI::DrawElement(const size_t numberOfIndices)
    {
        glDrawElements(GL_TRIANGLES, numberOfIndices, GL_UNSIGNED_INT, nullptr);
    }

    std::expected<Buffer, BufferCreationError> OpenGLRHI::CreateBuffer(const BufferDescription& description)
    {
        if (description.Type == BufferType::Vertex)
        {
            GLuint vbo;
            glGenBuffers(1, &vbo);
            return Buffer{.Index = vbo, .Type = description.Type};
        }
        if (description.Type == BufferType::Index)
        {
            GLuint ebo;
            glGenBuffers(1, &ebo);
            return Buffer{.Index = ebo, .Type = description.Type};
        }

        return std::unexpected(
            BufferCreationError{
                .ErrorCode = BufferCreationErrorCode::UnsupportedBufferType,
                .ErrorMessage = "Unsupported buffer type"
            }
        );
    }

    void OpenGLRHI::DestroyBuffer(const Buffer& buffer)
    {
        if (buffer.Type == BufferType::Vertex)
        {
            glDeleteBuffers(1, &buffer.Index);
        }
        if (buffer.Type == BufferType::Index)
        {
            glDeleteBuffers(1, &buffer.Index);
        }
    }

    void OpenGLRHI::BindBuffer(const Buffer& buffer)
    {
        if (buffer.Type == BufferType::Vertex)
        {
            glBindBuffer(GL_ARRAY_BUFFER, buffer.Index);
        }
        if (buffer.Type == BufferType::Index)
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffer.Index);
        }
    }

    std::expected<VertexArrayObject, VertexArrayObjectCreationError> OpenGLRHI::CreateVertexArrayObject(
        const VertexArrayObjectDescription& description
    )
    {
        GLuint vao;
        glGenVertexArrays(1, &vao);

        glBindVertexArray(vao);
        for (size_t i = 0; i < description.NumberOfAttributes; ++i)
        {
            const auto& attributeDescription = description.Attributes[i];

            if (attributeDescription.Type != AttributeType::Float)
            {
                return std::unexpected(
                    VertexArrayObjectCreationError{
                        .ErrorCode = VertexArrayObjectCreationErrorCode::UnsupportedAttributeType,
                        .ErrorMessage = "Unsupported attribute type"
                    }
                );
            }

            // TODO: Ensure unit of .Size is correct, currently multiply it internally.
            glVertexAttribPointer(
                attributeDescription.Index, attributeDescription.Size, GL_FLOAT, GL_FALSE,
                attributeDescription.Size * sizeof(float),
                reinterpret_cast<void*>(attributeDescription.Offset)
            );
            glEnableVertexAttribArray(attributeDescription.Index);
        }

        return VertexArrayObject{.ID = vao};
    }

    void OpenGLRHI::DestroyVertexArrayObject(const VertexArrayObject& vertexArrayObject)
    {
        glDeleteVertexArrays(1, &vertexArrayObject.ID);
    }

    void OpenGLRHI::BindVertexArrayObject(const VertexArrayObject& vertexArrayObject)
    {
        glBindVertexArray(vertexArrayObject.ID);
    }

    std::expected<Shader, ShaderCreationError> OpenGLRHI::CreateShader(
        const std::string_view vertexShader, const std::string_view fragmentShader
    )
    {
        auto compileShader = [](const std::string_view vertexShader,
                                const GLuint shaderType) -> std::expected<GLuint, ShaderCreationError>
        {
            const auto shaderID = glCreateShader(shaderType);
            const char* sourcePtr = vertexShader.data();
            glShaderSource(shaderID, 1, &sourcePtr, nullptr);
            glCompileShader(shaderID);

            int success;
            static char shaderCompileInfoLog[512];
            glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

            if (success == GL_FALSE)
            {
                glGetShaderInfoLog(shaderID, 512, nullptr, shaderCompileInfoLog);
                return std::unexpected(
                    ShaderCreationError{
                        .ErrorCode = ShaderCreationErrorCode::CompilationFailed,
                        .ErrorMessage = shaderCompileInfoLog
                    }
                );
            }

            return shaderID;
        };

        const auto vertexShaderIDResult = compileShader(vertexShader, GL_VERTEX_SHADER);
        if (!vertexShaderIDResult)
        {
            return std::unexpected(vertexShaderIDResult.error());
        }
        const auto fragmentShaderIDResult = compileShader(fragmentShader, GL_FRAGMENT_SHADER);
        if (!fragmentShaderIDResult)
        {
            return std::unexpected(fragmentShaderIDResult.error());
        }

        const auto vertexShaderID = vertexShaderIDResult.value();
        const auto fragmentShaderID = fragmentShaderIDResult.value();

        const auto shaderProgramID = glCreateProgram();
        glAttachShader(shaderProgramID, vertexShaderID);
        glAttachShader(shaderProgramID, fragmentShaderID);
        glLinkProgram(shaderProgramID);

        int success;
        static char ShaderProgramLinkInfoLog[512];
        glGetProgramiv(shaderProgramID, GL_LINK_STATUS, &success);
        if (success == GL_FALSE)
        {
            glGetProgramInfoLog(shaderProgramID, 512, nullptr, ShaderProgramLinkInfoLog);
            return std::unexpected(
                ShaderCreationError{
                    .ErrorCode = ShaderCreationErrorCode::LinkingFailed,
                    .ErrorMessage = ShaderProgramLinkInfoLog
                }
            );
        }

        // Delete shaders (not shader program)
        glDeleteShader(vertexShaderID);
        glDeleteShader(fragmentShaderID);

        return Shader{.ID = shaderProgramID};
    }

    void OpenGLRHI::DestroyShader(const Shader& shader)
    {
        glDeleteProgram(shader.ID);
    }

    void OpenGLRHI::BindShader(const Shader& shader)
    {
        glUseProgram(shader.ID);
    }
}