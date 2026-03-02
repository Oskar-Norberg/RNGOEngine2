//
// Created by ringo on 2026-02-21.
//

#include "Rendering/RenderRunnable.h"

#include "Error/Error.h"
#include "Rendering/RHI/Implementation/OpenGLRHI.h"

namespace rngo
{
    RenderRunnable::RenderRunnable(AssetRegistry& registry, IWindow* window)
        : m_assetRegistry(registry), m_window(window)
    {
    }

    void RenderRunnable::InitializeInternal()
    {
        Runnable::InitializeInternal();

        m_window->MakeCurrentContext();
        m_window->LoadGLAD();

        const auto renderType = m_window->GetRenderType();
        if (std::holds_alternative<OpenGLWindowConfig>(renderType))
        {
            m_rhi = std::make_unique<OpenGLRHI>();
        }
        else
        {
            RNGO_FATAL_ERROR("Unsupported Render Type, no RHI backend found");
        }
    }

    void RenderRunnable::TickInternal()
    {
        Runnable::TickInternal();

        // Consume Loaded Resources
        ConsumeReadyResources();

        // Render Loop
        std::array clearColor = {0.0f, 0.5f, 0.5f, 1.0f};
        m_rhi->SetClearColor(clearColor);
        m_rhi->ClearTarget(ClearTargetBit::Color);

        m_window->SwapBuffers();
    }

    void RenderRunnable::ExitInternal()
    {
        Runnable::ExitInternal();
    }

    void RenderRunnable::ConsumeReadyResources()
    {
    }
}