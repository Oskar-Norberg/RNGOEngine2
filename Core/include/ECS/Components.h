//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <glm/detail/type_quat.hpp>
#include <glm/glm.hpp>

#include "ECS/ComponentReflection.h"

namespace rngo
{
    struct Transform
    {
        glm::vec3 Position;
        glm::quat Rotation;
        glm::vec3 Scale;
    };
    RNGO_REFLECT_BEGIN(Transform, Transform)
        RNGO_REFLECT_PROPERTY(Transform, Position)
        RNGO_REFLECT_PROPERTY(Transform, Rotation)
        RNGO_REFLECT_PROPERTY(Transform, Scale)
    RNGO_REFLECT_END(Transform)
}