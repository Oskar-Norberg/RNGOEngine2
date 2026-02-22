//
// Created by ringo on 2026-02-22.
//

#pragma once

#include "Utilities/EnumDefinitions.h"

namespace rngo
{
    enum class RenderFeatureBit
    {
        None = 0,
        DepthTesting = 1 << 0,
        Blending = 1 << 1,
        BackFaceCulling = 1 << 2,
    };
    DEFINE_ENUM_CLASS_BITWISE_OPERATORS(RenderFeatureBit)
}