//
// Created by ringo on 2026-02-20.
//

#include "ECS/Components.h"
#include "ECS/World.h"

int main()
{
    rngo::World world;

    auto testEntity = world.CreateEntity();
    testEntity.AddComponent<rngo::Transform>(rngo::Transform{
        glm::vec3{123.0f, 234.0f, 345.0f},
        glm::quat{},
        glm::vec3{1.0f},
    });

    return 0;
}