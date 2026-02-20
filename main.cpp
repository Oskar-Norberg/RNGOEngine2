//
// Created by ringo on 2026-02-20.
//

#include <iostream>

#include "ECS/Systems/SystemContext.h"
#include "ECS/Systems/SystemScheduler.h"
#include "ECS/World.h"

void TestSystem(rngo::World& world, rngo::EngineSystemContext& context)
{
    const auto intView = world.GetRegistry().view<int>();
    for (const auto& [entity, intVal] : intView.each())
    {
        std::cout << intVal << std::endl;
    }
}

int main()
{
    rngo::EngineSystemContext context;
    rngo::SystemScheduler<rngo::EngineSystemContext> scheduler;

    rngo::World world;

    scheduler.AddSystem(TestSystem);

    auto entity = world.CreateEntity();
    entity.AddComponent<int>(5);

    scheduler.Update(world, context);
}