//
// Created by ringo on 2026-02-22.
//

#pragma once

#include <cstdint>
#include <string>

namespace rngo
{
    // NOTE: In an OpenGL context, I chose to skip the concept of a "Shader" and opt to always compile them into ShaderPrograms.
    // Maybe this will come back to bite me in the ass. But the whole RHI would need to be redesigned in such a case anyways.
    // Fine for now!
    struct Shader
    {
        std::uint32_t ID;
    };

    enum class ShaderCreationErrorCode
    {
        CompilationFailed,
        LinkingFailed,
    };

    struct ShaderCreationError
    {
        ShaderCreationErrorCode ErrorCode;
        // blah blah blah consider a fixed-size string yada yada
        std::string ErrorMessage;
    };
}
