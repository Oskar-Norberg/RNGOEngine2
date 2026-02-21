//
// Created by ringo on 2026-02-21.
//

#include "Application.h"

#include <chrono>

#include "Events/EngineEvents.h"
#include "Rendering/Window/GLFWWindow.h"

namespace rngo
{
    Application::Application(const ApplicationConfig& config)
        : m_isRunning(false)
    {
        WindowConfig windowConfig{
            .Title = config.Title,
            .Height = config.Height,
            .Width = config.Width,
            .RenderType = OpenGLWindowConfig{4, 6},
            .VSync = true
        };

        m_window = std::make_unique<GLFWWindow>(windowConfig);
        m_renderRunnable = std::make_unique<RenderRunnable>(m_window.get());
    }

    Application::~Application() = default;

    void Application::Run()
    {
        m_isRunning = true;

        std::thread renderThread(&RenderRunnable::Run, m_renderRunnable.get());

        // TODO: Use a fixed time-step for systems.
        auto lastFrame = std::chrono::high_resolution_clock::now();
        while (m_isRunning)
        {
            const float deltaTime =
                std::chrono::duration<float>(std::chrono::high_resolution_clock::now() - lastFrame).count();
            lastFrame = std::chrono::high_resolution_clock::now();

            m_window->PollEvents(m_eventQueue);
            OnUpdate();

            // TODO: TEMPORARY DEBUGGING CODE
            const auto events = m_eventQueue.GetEvents();
            for (const auto& event : events)
            {
                if (event->GetType() == EventType::ExitRequested)
                {
                    m_isRunning = false;
                }
            }
        }

        m_renderRunnable->Stop();
        renderThread.join();
    }
}