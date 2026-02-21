//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <memory>

#include "Application.h"

namespace rngo
{
    extern std::unique_ptr<Application> CreateApplication();

    inline int Main(const int argc, char** argv)
    {
        // TODO: Initialize Logger? To keep it outside of the Application?
        const auto app = CreateApplication();
        app->Run();

        return 0;
    }
}
