//
// Created by ringo on 2026-02-22.
//

#pragma once

#include <atomic>
#include <exception>

namespace rngo
{
    class SharedExecutionContext
    {
    public:
        explicit SharedExecutionContext(const bool isRunning)
            : m_isRunning(isRunning), m_exception(nullptr), m_mutex()
        {
        }

        ~SharedExecutionContext() = default;

        SharedExecutionContext(const SharedExecutionContext& other) = delete;
        SharedExecutionContext(SharedExecutionContext&& other) noexcept = delete;
        SharedExecutionContext& operator=(const SharedExecutionContext& other) = delete;
        SharedExecutionContext& operator=(SharedExecutionContext&& other) noexcept = delete;

    public:
        bool IsRunning()
        {
            return m_isRunning;
        }

        void Stop()
        {
            m_isRunning = false;
        }

        void StopWithException(std::exception_ptr&& exception)
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            // Don't override existing error
            if (m_exception == nullptr)
            {
                m_exception = std::move(exception);
            }
            m_isRunning = false;
        }

        std::exception_ptr GetException()
        {
            std::lock_guard<std::mutex> lock(m_mutex);
            return m_exception;
        }

    private:
        std::atomic<bool> m_isRunning;
        std::exception_ptr m_exception;
        std::mutex m_mutex;
    };
}
