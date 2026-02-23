//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include "Utilities/EnumDefinitions.h"

namespace rngo
{
    enum class ThreadType
    {
        None = 0,
        Main = 1 << 0,
        Render = 1 << 1
    };
    DEFINE_ENUM_CLASS_BITWISE_OPERATORS(ThreadType);
}