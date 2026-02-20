//
// Created by ringo on 2026-02-20.
//

#pragma once

#include <entt/entt.hpp>

namespace rngo
{
    struct Entity
    {
        entt::entity ID;
        entt::registry& registry;

        template<typename TComponent, typename... Args>
        auto AddComponent(Args&&... args) -> decltype(registry.emplace<TComponent>(ID))
        {
            return registry.emplace<TComponent>(ID, std::forward<Args>(args)...);
        }
    };
}
