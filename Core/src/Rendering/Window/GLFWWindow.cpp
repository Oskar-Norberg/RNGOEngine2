//
// Created by ringo on 2026-02-21.
//

#include "Rendering/Window/GLFWWindow.h"

#include "Events/EngineEvents.h"
#include "Events/EventQueue.h"
#include "Logging/Logger.h"
#include "Utilities/RNGOAsserts.h"

namespace rngo
{
    GLFWWindow::GLFWWindow(const WindowConfig& config)
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
            RNGO_ASSERT(false && "Unsupported Render Type");
            // TODO: Throw irrecoverable error, going into UB land
        }

        m_rawWindow = glfwCreateWindow(config.Width, config.Height, config.Title.data(), nullptr, nullptr);
        if (m_rawWindow == nullptr)
        {
            RNGO_LOG(LogLevel::Critical, "Failed to create GLFW window.");
            glfwTerminate();
            RNGO_ASSERT(false && "Failed to create GLFW window.");
            // TODO: Throw Irrecoverable error
            // TODO: UB
        }
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
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
        {
            RNGO_ASSERT(false && "Failed to initialize GLAD.");
            // TODO: Throw Irrecoverable error
            // TODO: UB
        }
    }

    void GLFWWindow::MakeCurrentContext()
    {
        glfwMakeContextCurrent(m_rawWindow);
    }
}
