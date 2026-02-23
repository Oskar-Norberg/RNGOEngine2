//
// Created by ringo on 2026-02-21.
//

#pragma once

#include "Application.h"

namespace rngo_editor
{
    class Editor : public rngo::Application
    {
    public:
        explicit Editor(const rngo::ApplicationConfig& config);

    protected:
        void OnUpdate(float deltaTime) override;
    };
}
