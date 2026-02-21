//
// Created by ringo on 2026-02-21.
//

#include "Rendering/RenderRunnable.h"

namespace rngo
{
    RenderRunnable::RenderRunnable(IWindow* window)
        : m_window(window)
    {
    }

    void RenderRunnable::InitializeInternal()
    {
        Runnable::InitializeInternal();

        m_window->MakeCurrentContext();
        m_window->LoadGLAD();
    }

    void RenderRunnable::TickInternal()
    {
        Runnable::TickInternal();

        m_window->SwapBuffers();
    }

    void RenderRunnable::ExitInternal()
    {
        Runnable::ExitInternal();
    }
}