//
// Created by ringo on 2026-02-21.
//

#pragma once

#include "RHI/IRHI.h"
#include "Utilities/Threading/Runnable.h"
#include "Window/IWindow.h"

namespace rngo
{
    class RenderRunnable : public Runnable
    {
    public:
        // TODO: Pass Window by weak_ptr perhaps?
        explicit RenderRunnable(IWindow* window);

    protected:
        void InitializeInternal() override;
        void TickInternal() override;
        void ExitInternal() override;

    private:
        IWindow* m_window;
        std::unique_ptr<IRHI> m_rhi;
    };
}