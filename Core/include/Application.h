//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <memory>

#include "Rendering/RenderRunnable.h"
#include "Rendering/Window/IWindow.h"

namespace rngo
{
    struct ApplicationConfig
    {
        std::string_view Title;
        int Width = 1280;
        int Height = 720;

        bool VSync = true;
    };

    class Application
    {
    public:
        explicit Application(const ApplicationConfig& config);
        virtual ~Application();

        void Run();

    protected:
        bool m_isRunning;

        std::unique_ptr<IWindow> m_window;
        std::unique_ptr<RenderRunnable> m_renderRunnable;

    protected:
        virtual void OnUpdate()
        {
        }
    };
}