//
// Created by ringo on 2026-02-21.
//

#pragma once

namespace rngo
{
    class Application
    {
    public:
        Application();
        virtual ~Application();

        void Run();

    protected:
        bool m_isRunning;
    protected:
        virtual void OnUpdate() {}
        virtual void OnRender() {}

    };
}