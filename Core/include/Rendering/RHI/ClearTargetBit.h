//
// Created by ringo on 2026-02-22.
//

#pragma once

#include "Utilities/EnumDefinitions.h"

namespace rngo
{
    enum class ClearTargetBit
    {
        None = 0,
        Color = 1 << 0,
        Depth = 1 << 1,
        Stencil = 1 << 2,
    };
    DEFINE_ENUM_CLASS_BITWISE_OPERATORS(ClearTargetBit)
}
