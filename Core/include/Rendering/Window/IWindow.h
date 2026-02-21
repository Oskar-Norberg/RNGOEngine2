//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <variant>

namespace rngo
{
    struct OpenGLWindowConfig
    {
        int Major, Minor;
    };

    struct WindowConfig
    {
        std::string_view Title;
        int Height, Width;
        std::variant<OpenGLWindowConfig> RenderType;
        bool VSync;
    };

    class IWindow
    {
    public:
        virtual ~IWindow() = default;

    public:
        virtual void SwapBuffers() = 0;
        virtual void SetTitle(std::string_view title) = 0;

    public:
        virtual void LoadGLAD() = 0;
        virtual void MakeCurrentContext() = 0;
    };
}