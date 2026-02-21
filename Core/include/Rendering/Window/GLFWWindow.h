//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <GLFW/glfw3.h>
#include <glad/gl.h>

#include <string_view>

#include "IWindow.h"

namespace rngo
{
    class GLFWWindow : public IWindow
    {
    public:
        explicit GLFWWindow(const WindowConfig& config);

    public:
        void PollEvents(EventQueue& eventQueue) override;

    public:
        void SwapBuffers() override;
        void SetTitle(std::string_view title) override;

    public:
        void LoadGLAD() override;
        void MakeCurrentContext() override;

    private:
        GLFWwindow* m_rawWindow;
    };
}