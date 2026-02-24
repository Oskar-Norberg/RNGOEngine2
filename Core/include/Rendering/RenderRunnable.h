//
// Created by ringo on 2026-02-21.
//

#pragma once

#include "Asset/AssetRegistry/AssetRegistry.h"
#include "RHI/IRHI.h"
#include "Utilities/Threading/Runnable.h"
#include "Window/IWindow.h"

namespace rngo
{
    class RenderRunnable : public Runnable
    {
    public:
        // TODO: Pass Window by weak_ptr perhaps?
        explicit RenderRunnable(AssetRegistry& registry, IWindow* window);

    protected:
        void InitializeInternal() override;
        void TickInternal() override;
        void ExitInternal() override;

    private:
        AssetRegistry& m_assetRegistry;
        IWindow* m_window;
        std::unique_ptr<IRHI> m_rhi;

    private:
        void ConsumeReadyResources();
    };
}