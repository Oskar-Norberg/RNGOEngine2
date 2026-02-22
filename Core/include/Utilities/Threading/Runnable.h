//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <atomic>
#include <mutex>

#include "Utilities/RNGOAsserts.h"

namespace rngo
{
    // A base class for any task that can be run on a separate thread or on the main thread.
    class Runnable
    {
    public:
        virtual ~Runnable() = default;

        // Blocking API. Will run until stopped.
    public:
        void Run()
        {
            EnsureInitialized();

            while (m_isRunning)
            {
                Tick();
            }

            ExitInternal();
        }

        // Non-blocking, tick once API.
    public:
        void Initialize()
        {
            InitializeInternal();
        }

        void Tick()
        {
            EnsureInitialized();
            TickInternal();
        }

        // Shared API
    public:
        void Stop()
        {
            EnsureExited();
        }

    protected:
        virtual void InitializeInternal()
        {
        }
        virtual void TickInternal()
        {
        }
        virtual void ExitInternal()
        {
        }

    protected:
        std::atomic<bool> m_isRunning{false};

        std::once_flag m_initFlag;
        std::once_flag m_exitFlag;

    private:
        void EnsureInitialized()
        {
            std::call_once(
                m_initFlag,
                [this]()
                {
                    InitializeInternal();
                    m_isRunning = true;
                }
            );
        }

        void EnsureExited()
        {
            std::call_once(
                m_exitFlag,
                [this]()
                {
                    ExitInternal();
                    m_isRunning = false;
                }
            );
        }
    };
}