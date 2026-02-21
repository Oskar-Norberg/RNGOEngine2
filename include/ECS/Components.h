//
// Created by ringo on 2026-02-21.
//

#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/detail/type_quat.hpp>
#include <glm/glm.hpp>

#include "entt/meta/factory.hpp"

namespace rngo
{
    static auto s_vec3 = entt::meta_factory<glm::vec3>{}
                             .type("Vector3")
                             .data<&glm::vec3::x>("x")
                             .data<&glm::vec3::y>("y")
                             .data<&glm::vec3::z>("z")
                             .ctor<>();
    static auto s_quat = entt::meta_factory<glm::quat>{}
                             .type("Quaternion")
                             .data<&glm::quat::x>("x")
                             .data<&glm::quat::y>("y")
                             .data<&glm::quat::z>("z")
                             .data<&glm::quat::w>("w")
                             .ctor<>();

    struct TestComponent
    {
        float x;
        float y;
        int z;
    };
    static auto s_testMeta = entt::meta_factory<TestComponent>{}
                                 .type("TestComponent")
                                 .data<&TestComponent::x>("x")
                                 .data<&TestComponent::y>("y")
                                 .data<&TestComponent::z>("z")
                                 .ctor<>();

    struct Transform
    {
        glm::vec3 Position;
        glm::quat Rotation;
        glm::vec3 Scale;
    };
    static auto s_transformMeta = entt::meta_factory<Transform>{}
                                      .type("Transform")
                                      .data<&Transform::Position>("Position")
                                      .data<&Transform::Rotation>("Rotation")
                                      .data<&Transform::Scale>("Scale")
                                      .ctor<>();

    // static auto s_transformMeta = entt::meta_factory<rngo::Transform>{}
    //                                    .type("Transform"_hs)
    //                                    .data<&rngo::Transform::Position>("Position"_hs)
    //                                    .data<&rngo::Transform::Rotation>("Rotation"_hs)
    //                                    .data<&rngo::Transform::Scale>("Scale"_hs)
    //                                    .ctor<>();
}