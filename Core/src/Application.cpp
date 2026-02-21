//
// Created by ringo on 2026-02-21.
//

#include "Application.h"

#include <chrono>

namespace rngo
{
    Application::Application()
        : m_isRunning(false)
    {
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