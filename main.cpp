//
// Created by ringo on 2026-02-20.
//

#include <iostream>
#include <print>

#include "ECS/Components.h"
#include "ECS/Systems/SystemContext.h"
#include "ECS/Systems/SystemScheduler.h"
#include "ECS/World.h"

void ResolveEnTTMetaAny(const entt::meta_any& any)
{
    // Int
    if (const auto* integer = any.try_cast<int>(); integer != nullptr)
    {
        std::cout << *integer << '\n';
    }

    // Float
    if (const auto* floatingPoint = any.try_cast<float>(); floatingPoint != nullptr)
    {
        std::cout << *floatingPoint << '\n';
    }

    // Bool
    if (const auto* boolean = any.try_cast<bool>(); boolean != nullptr)
    {
        std::cout << *boolean << '\n';
    }

    // String
    if (const auto* stdString = any.try_cast<std::string>(); stdString != nullptr)
    {
        std::cout << *stdString << '\n';
    }

    // Vec3
    if (const auto* vec3 = any.try_cast<glm::vec3>(); vec3 != nullptr)
    {
        std::cout << vec3->x << ", " << vec3->y << ", " << vec3->z << '\n';
    }
}

int main()
{
    rngo::World world;
    auto& registry = world.GetRegistry();

    rngo::EngineSystemContext context{.World = &world};
    rngo::SystemScheduler<rngo::EngineSystemContext> scheduler;

    auto testEntity = world.CreateEntity();
    testEntity.AddComponent<rngo::TestComponent>(rngo::TestComponent{1.0f, 2.0f, 3});
    testEntity.AddComponent<rngo::Transform>(rngo::Transform{
        glm::vec3{123.0f, 234.0f, 345.0f},
        glm::quat{},
        glm::vec3{1.0f},
    });

    const auto allView = registry.view<entt::entity>();
    // TODO: O(n^2)
    for (const auto entity : allView)
    {
        const auto registeredMetaTypes = entt::resolve();
        for (const auto& [metaTypeID, metaType] : registeredMetaTypes)
        {
            const auto storages = registry.storage();
            for (const auto& [storageTypeID, storage] : storages)
            {
                if (storage.contains(entity))
                {
                    if (metaTypeID == storageTypeID)
                    {
                        void* componentPtr = storage.value(entity);
                        entt::meta_any instance = metaType.from_void(componentPtr);

                        std::cout << "Entity has registered component: " << metaType.name() << "\n";
                        std::cout << "Registered Type has data:" << "\n";
                        for (const auto& [dataTypeID, metaData] : metaType.data())
                        {
                            std::cout << metaData.name() << ": ";
                            const auto& anyRef = metaData.get(instance);
                            ResolveEnTTMetaAny(anyRef);
                        }
                    }
                }
            }
        }
    }

    scheduler.Update(context);
}