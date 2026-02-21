//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <GLFW/glfw3.h>
#include <string_view>

#include "IWindow.h"

namespace rngo
{
    class GLFWWindow : public IWindow
    {
    public:
        GLFWWindow(int height, int width, std::string_view name, bool vsync);
    };
}