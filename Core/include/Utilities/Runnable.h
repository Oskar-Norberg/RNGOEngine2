//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <atomic>
#include <thread>

#include "RNGOAsserts.h"

namespace rngo
{
    // A base class for any task that can be run on a separate thread or on the main thread.
    class Runnable
    {
    public:
        virtual ~Runnable() = default;

        // Non-blocking, Multi-threaded API
    public:
        void Run()
        {
            Initialize();

            m_isRunning = true;
            while (m_isRunning)
            {
                TickInternal();
            }

            ExitInternal();
        }

        // Blocking, Single-Threaded API
    public:
        void Initialize()
        {
            m_isInitialized = true;
            InitializeInternal();
        }

        void Tick()
        {
            RNGO_ASSERT(m_isInitialized && "Tried to Tick uninitialized Runnable");
            TickInternal();
        }

        // Shared
    public:
        void Stop()
        {
            m_isRunning = false;
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
        std::atomic<bool> m_isInitialized = false;
        std::atomic<bool> m_isRunning = false;
    };
}