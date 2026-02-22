//
// Created by ringo on 2026-02-21.
//

#include "Rendering/Window/GLFWWindow.h"

#include "Error/Error.h"
#include "Events/EngineEvents.h"
#include "Events/EventQueue.h"
#include "Logging/Logger.h"
#include "Utilities/RNGOAsserts.h"

namespace rngo
{
    GLFWWindow::GLFWWindow(const WindowConfig& config)
        : m_renderType(config.RenderType)
    {
        glfwInit();

        // Initialize based on RenderType
        if (std::holds_alternative<OpenGLWindowConfig>(config.RenderType))
        {
            const auto& openGLConfig = std::get<OpenGLWindowConfig>(config.RenderType);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, openGLConfig.Major);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, openGLConfig.Minor);
            // NOTE: Only support Core.
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        }
        else
        {
            RNGO_FATAL_ERROR("Unsupported Render Type");
        }

        m_rawWindow = glfwCreateWindow(config.Width, config.Height, config.Title.data(), nullptr, nullptr);
        if (m_rawWindow == nullptr)
        {
            RNGO_LOG(LogLevel::Critical, "Failed to create GLFW window.");
            glfwTerminate();
            RNGO_FATAL_ERROR("Unsupported Render Type");
        }

        // TODO: Set VSync
    }

    void GLFWWindow::PollEvents(EventQueue& eventQueue)
    {
        glfwPollEvents();

        if (glfwWindowShouldClose(m_rawWindow))
        {
            eventQueue.EmplaceEvent<ExitRequestedEvent>();
        }
    }

    void GLFWWindow::SwapBuffers()
    {
        glfwSwapBuffers(m_rawWindow);
    }

    void GLFWWindow::SetTitle(const std::string_view title)
    {
        glfwSetWindowTitle(m_rawWindow, title.data());
    }

    void GLFWWindow::LoadGLAD()
    {
        if (std::holds_alternative<OpenGLWindowConfig>(m_renderType))
        {
            const auto& openGLConfig = std::get<OpenGLWindowConfig>(m_renderType);
            if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
            {
                RNGO_FATAL_ERROR("Failed to initialize GLAD.");
            }
        }
        else
        {
            RNGO_FATAL_ERROR("Unsupported RenderType.");
        }
    }

    void GLFWWindow::MakeCurrentContext()
    {
        glfwMakeContextCurrent(m_rawWindow);
    }

    RenderType GLFWWindow::GetRenderType()
    {
        return m_renderType;
    }
}
