//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <memory>

#include "Application.h"
#include "Logging/Logger.h"

namespace rngo
{
    extern std::unique_ptr<Application> CreateApplication();

    inline int Main(const int argc, char** argv)
    {
        Logger::InitializeLogger();

        const auto app = CreateApplication();
        app->Run();

        Logger::ExitLogger();

        return 0;
    }
}
