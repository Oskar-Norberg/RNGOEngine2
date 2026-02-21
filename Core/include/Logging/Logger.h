//
// Created by Oskar.Norberg on 2025-11-25.
//

#pragma once

#include <spdlog/spdlog.h>

#include <chrono>
#include <source_location>
#include <string>
#include <string_view>

#include "LogLevel.h"
#include "Utilities/Singleton.h"

namespace rngo
{
    struct LogLocation
    {
        std::string_view File;
        std::string_view Function;
        size_t Line;
    };

    struct LogEntry
    {
        LogLevel Level;
        std::string Message;
        LogLocation Location;
        std::chrono::time_point<std::chrono::system_clock> TimePoint;
    };

    // TODO: Consider giving logs a category, could be thread or else.
    class Logger
    {
    public:
        static void InitializeLogger();
        static void ExitLogger();

        template<typename... Args>
        static void Log(
            const std::source_location location, const LogLevel level, spdlog::format_string_t<Args...> fmt,
            Args&&... args
        )
        {
#ifndef NDEBUG
            if (s_logger == nullptr)
            {
                RNGO_ASSERT(false && "Logger has not been initialized");
            }
#endif

            spdlog::source_loc loc{
                location.file_name(), static_cast<int>(location.line()), location.function_name()
            };

            const auto logLevel = RNGOLevelToSPDLogLevel(level);
            s_logger->log(loc, logLevel, fmt, std::forward<Args>(args)...);
        }

    private:
        static std::unique_ptr<spdlog::logger> s_logger;
    };
}

#define RNGO_LOG(level, ...) rngo::Logger::Log(std::source_location::current(), level, __VA_ARGS__)
