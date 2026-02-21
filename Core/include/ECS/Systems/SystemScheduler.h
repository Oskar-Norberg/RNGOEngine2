#pragma once

#include <vector>

namespace rngo
{
    template<typename TSystemContext>
    class SystemScheduler
    {
    public:
        using SystemFn = void (*)(TSystemContext&);

    public:
        void Update(TSystemContext& context)
        {
            for (const auto& sysFunc : m_systems)
            {
                sysFunc(context);
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