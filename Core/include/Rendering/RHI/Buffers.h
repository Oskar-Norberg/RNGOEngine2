//
// Created by ringo on 2026-02-22.
//

#pragma once

#include <cstdint>
#include <string>

namespace rngo
{
    enum class BufferType
    {
        Vertex,
        Index
    };

    struct Buffer
    {
        std::uint32_t Index;
        BufferType Type;
    };

    enum class BufferUsage
    {
        STATIC_DRAW,
        DYNAMIC_DRAW,
        STREAM_DRAW
    };

    struct BufferDescription
    {
        BufferType Type;
        BufferUsage Usage;
    };

    enum class BufferCreationErrorCode
    {
        OutOfMemory,
        UnsupportedBufferType
    };

    struct BufferCreationError
    {
        BufferCreationErrorCode ErrorCode;
        // TODO: Consider fixed-size string as error.
        std::string ErrorMessage;
    };
}