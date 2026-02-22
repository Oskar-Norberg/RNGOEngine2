//
// Created by ringo on 2026-02-22.
//

#pragma once

#include <array>
#include <cstdint>
#include <string>

namespace rngo
{
    struct VertexArrayObject
    {
        std::uint32_t ID;
    };

    // Add more as necessary
    enum class AttributeType
    {
        Float,
    };

    struct Attribute
    {
        AttributeType Type;
        size_t Index;
        size_t Size;
        size_t Stride;
        size_t Offset;
    };

    constexpr auto MAX_NR_VERTEX_ATTRIBUTES = 8;
    struct VertexArrayObjectDescription
    {
        std::array<Attribute, MAX_NR_VERTEX_ATTRIBUTES> Attributes;
        size_t NumberOfAttributes;
    };

    enum class VertexArrayObjectCreationErrorCode
    {
        InvalidAttribute,
        InvalidAttributeIndex,
        UnsupportedAmountOfAttributes,
        UnsupportedAttributeType
    };

    struct VertexArrayObjectCreationError
    {
        VertexArrayObjectCreationErrorCode ErrorCode;
        // blah blah blah consider a fixed-size string yada yada
        std::string ErrorMessage;
    };
}