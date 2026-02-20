#pragma once

#include <vector>

#include "ECS/World.h"

namespace rngo
{
    template<typename TSystemContext>
    class SystemScheduler
    {
    public:
        using SystemFn = void (*)(World&, TSystemContext&);

    public:
        void Update(World& world, TSystemContext& context)
        {
            for (const auto& sysFunc : m_systems)
            {
                sysFunc(world, context);
            }
        }

    public:
        void AddSystem(SystemFn system)
        {
            m_systems.push_back(system);
        }

    private:
        std::vector<SystemFn> m_systems;
    };
}