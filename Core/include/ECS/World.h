//
// Created by SkummisDenAndre on 2025-06-16.
//

#pragma once

#include <entt/entt.hpp>

#include "ECS/Entity.h"

namespace rngo
{
    class World
    {
    public:
        Entity CreateEntity()
        {
            const auto id = m_registry.create();
            return Entity{id, m_registry};
        }

    public:
        void DestroyEntity(const Entity entity)
        {
            m_registry.destroy(entity.ID);
        }

        void DestroyEntity(const entt::entity entity)
        {
            m_registry.destroy(entity);
        }

    public:
        // TODO: Goal is for only systems to access the Registry directly. But for now, other parts might need it too.
        entt::registry& GetRegistry()
        {
            return m_registry;
        }

        const entt::registry& GetRegistry() const
        {
            return m_registry;
        }

    private:
        entt::registry m_registry;
    };
}