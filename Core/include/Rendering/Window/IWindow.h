//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <string_view>
#include <variant>

namespace rngo
{
    class EventQueue;
}

namespace rngo
{
    struct OpenGLWindowConfig
    {
        int Major, Minor;
    };

    using RenderType = std::variant<OpenGLWindowConfig>;

    struct WindowConfig
    {
        std::string_view Title;
        int Height, Width;
        RenderType RenderType;
        bool VSync;
    };

    class IWindow
    {
    public:
        virtual ~IWindow() = default;

    public:
        virtual void PollEvents(EventQueue& eventQueue) = 0;

    public:
        virtual void SwapBuffers() = 0;
        virtual void SetTitle(std::string_view title) = 0;

    public:
        virtual void LoadGLAD() = 0;
        virtual void MakeCurrentContext() = 0;
        virtual RenderType GetRenderType() = 0;
    };
}