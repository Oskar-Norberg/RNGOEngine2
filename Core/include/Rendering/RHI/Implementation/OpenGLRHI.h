//
// Created by ringo on 2026-02-22.
//

#pragma once

#include "Rendering/RHI/IRHI.h"

namespace rngo
{
    class OpenGLRHI : public IRHI
    {
    public:
        void SetViewportSize(int width, int height) override;
        void EnableFeatures(RenderFeatureBit features) override;
        void DisableFeatures(RenderFeatureBit features) override;
    public:
        void SetClearColor(std::span<const float, 4> color) override;
        void ClearTarget(ClearTargetBit clearTarget) override;
    public:
        void DrawElement(size_t numberOfIndices) override;
    public:
        std::expected<Buffer, BufferCreationError> CreateBuffer(const BufferDescription& description) override;
        void DestroyBuffer(const Buffer& buffer) override;
        void BindBuffer(const Buffer& buffer) override;
    public:
        std::expected<VertexArrayObject, VertexArrayObjectCreationError> CreateVertexArrayObject(const VertexArrayObjectDescription& description) override;
        void DestroyVertexArrayObject(const VertexArrayObject& vertexArrayObject) override;
        void BindVertexArrayObject(const VertexArrayObject& vertexArrayObject) override;
    public:
        std::expected<Shader, ShaderCreationError> CreateShader(std::string_view vertexShader, std::string_view fragmentShader) override;
        void DestroyShader(const Shader& shader) override;
        void BindShader(const Shader& shader) override;
    };
}