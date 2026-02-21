//
// Created by Oskar.Norberg on 2025-11-25.
//

#include "Logging/Logger.h"

#include "spdlog/sinks/daily_file_sink.h"

namespace rngo
{
    constexpr auto LoggerName = "RNGOLog";
    constexpr auto LOG_PATH = "Logs/RNGOEngine.log";
    constexpr auto MAX_NR_LOG_FILES = 4;

    std::unique_ptr<spdlog::logger> Logger::s_logger{nullptr};

    void Logger::InitializeLogger()
    {
        s_logger = std::make_unique<spdlog::logger>(
            LoggerName,
            // Automatically log to file.
            std::make_shared<spdlog::sinks::daily_file_sink<std::mutex>>(
                LOG_PATH, 0, 0, false, MAX_NR_LOG_FILES
            )
        );
        // TODO: This should definitely not be set to debug in a release-build.
        s_logger->set_level(spdlog::level::debug);

        RNGO_LOG(LogLevel::Debug, "Logger Initialized");
    }

    void Logger::ExitLogger()
    {
        RNGO_LOG(LogLevel::Debug, "Logger Exiting...");
        s_logger->flush();
    }
}
