//
// Created by ringo on 2026-02-21.
//

#include "Application.h"

#include <chrono>

#include "Error/Error.h"
#include "Events/EngineEvents.h"
#include "Logging/Logger.h"
#include "Rendering/Window/GLFWWindow.h"
#include "Utilities/Threading/SharedExecutionContext.h"

namespace rngo
{
    Application::Application(const ApplicationConfig& config)
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
        SharedExecutionContext executionContext{true};

        auto& renderRunnable = *m_renderRunnable;
        std::thread renderThread(
            [&renderRunnable, &executionContext]()
            {
                try
                {
                    renderRunnable.Run();
                }
                catch (FatalEngineError& e)
                {
                    executionContext.StopWithException(std::make_exception_ptr(e));
                }

                renderRunnable.Stop();
            }
        );

        // TODO: Use a fixed time-step for systems.
        auto lastFrame = std::chrono::high_resolution_clock::now();
        while (executionContext.IsRunning())
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
                    executionContext.Stop();
                }
            }
        }

        m_renderRunnable->Stop();
        renderThread.join();

        if (const auto& exceptionPointer = executionContext.GetException())
        {
            std::rethrow_exception(exceptionPointer);
        }
    }
}