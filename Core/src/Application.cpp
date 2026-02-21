//
// Created by ringo on 2026-02-21.
//

#include "Application.h"

#include <chrono>

#include "Rendering/Window/GLFWWindow.h"

namespace rngo
{
    Application::Application(const ApplicationConfig& config)
        : m_isRunning(false)
    {
        m_window = std::make_unique<GLFWWindow>(config.Height, config.Width, config.Title, true);
    }

    Application::~Application() = default;

    void Application::Run()
    {
        m_isRunning = true;

        // TODO: Use a fixed time-step for systems.
        auto lastFrame = std::chrono::high_resolution_clock::now();
        while (m_isRunning)
        {
            const float deltaTime =
                std::chrono::duration<float>(std::chrono::high_resolution_clock::now() - lastFrame).count();
            lastFrame = std::chrono::high_resolution_clock::now();

            OnUpdate();
            OnRender();

            m_isRunning = false;
        }
    }
}