//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <atomic>

#include "Utilities/RNGOAsserts.h"

namespace rngo
{
    // A base class for any task that can be run on a separate thread or on the main thread.
    // TODO: Decide if Initialize should be called from run or not. Currently suffers from two-phase initialization.
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
                Tick();
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