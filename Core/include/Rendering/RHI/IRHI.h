//
// Created by ringo on 2026-02-22.
//

#pragma once

#include <expected>
#include <span>
#include <string_view>

#include "Buffers.h"
#include "ClearTargetBit.h"
#include "RenderFeatureBit.h"
#include "Shader.h"
#include "VertexArrayObject.h"

namespace rngo
{
    // NOTE: Really, really simple "RHI" to get OpenGL up and running.
    // This is not going to be compatible with any modern rendering-api.
    // But I figured wrapping it in an RHI object should make it easier to extend in the future.
    class IRHI
    {
    public:
        virtual ~IRHI() = default;

        // Setup
    public:
        virtual void SetViewportSize(int width, int height) = 0;
        virtual void EnableFeatures(RenderFeatureBit features) = 0;
        virtual void DisableFeatures(RenderFeatureBit features) = 0;

        // Clearing
    public:
        virtual void SetClearColor(std::span<const float, 4> color) = 0;
        virtual void ClearTarget(ClearTargetBit clearTarget) = 0;

        // Drawing
    public:
        virtual void DrawElement(size_t numberOfIndices) = 0;

        // Buffer
    public:
        virtual std::expected<Buffer, BufferCreationError> CreateBuffer(const BufferDescription& description) = 0;
        virtual void DestroyBuffer(const Buffer& buffer) = 0;
        virtual void BindBuffer(const Buffer& buffer) = 0;

        // Vertex Array Object
    public:
        virtual std::expected<VertexArrayObject, VertexArrayObjectCreationError> CreateVertexArrayObject(const VertexArrayObjectDescription& description) = 0;
        virtual void DestroyVertexArrayObject(const VertexArrayObject& vertexArrayObject) = 0;
        virtual void BindVertexArrayObject(const VertexArrayObject& vertexArrayObject) = 0;

        // Shader
    public:
        virtual std::expected<Shader, ShaderCreationError> CreateShader(std::string_view vertexShader, std::string_view fragmentShader) = 0;
        virtual void DestroyShader(const Shader& shader) = 0;
        virtual void BindShader(const Shader& shader) = 0;
    };
}