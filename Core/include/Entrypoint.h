//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <memory>

#include "Application.h"
#include "Error/Error.h"
#include "Logging/Logger.h"

namespace rngo
{
    extern std::unique_ptr<Application> CreateApplication();

    inline int Main(const int argc, char** argv)
    {
        int success = 0;

        Logger::InitializeLogger();

        try
        {
            const auto app = CreateApplication();
            app->Run();
        }
        catch (FatalEngineError& e)
        {
            success = 1;
            RNGO_LOG(LogLevel::Critical, "Fatal Error: {}", e.what());
            RNGO_LOG(LogLevel::Critical, "Shutting Down");
        }

        Logger::ExitLogger();

        return success;
    }
}
