//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <glm/detail/type_quat.hpp>
#include <glm/glm.hpp>

#include <entt/entt.hpp>

namespace rngo
{
    template<typename T>
    void EmplaceComponent(entt::registry* registry, const entt::entity entity)
    {
        registry->emplace<T>(entity);
    }

    // clang-format off
    // NOLINTBEGIN
#define RNGO_EMPLACE_FUNCTION_NAME entt::hashed_string{"ReflectEmplaceFunc"}

#define RNGO_REFLECT_STRINGIFY(name) name
#define RNGO_REFLECT_BEGIN(TypeName, SafeName) static const auto s_Reflection## SafeName## Registrar = entt::meta_factory<TypeName>{}.type(#SafeName)
#define RNGO_REFLECT_PROPERTY(TypeName, PropertyName) .data<&TypeName::PropertyName>(#PropertyName)
#define RNGO_REFLECT_END(TypeName) .func<&EmplaceComponent<TypeName>>(RNGO_EMPLACE_FUNCTION_NAME).ctor<>();
    // NOLINTEND
    // clang-format on

    // Set up Common Types
    RNGO_REFLECT_BEGIN(glm::vec3, Vec3)
        RNGO_REFLECT_PROPERTY(glm::vec3, x)
        RNGO_REFLECT_PROPERTY(glm::vec3, y)
        RNGO_REFLECT_PROPERTY(glm::vec3, z)
    RNGO_REFLECT_END(glm::vec3)

    RNGO_REFLECT_BEGIN(glm::vec4, Vec4)
        RNGO_REFLECT_PROPERTY(glm::vec4, x)
        RNGO_REFLECT_PROPERTY(glm::vec4, y)
        RNGO_REFLECT_PROPERTY(glm::vec4, z)
        RNGO_REFLECT_PROPERTY(glm::vec4, w)
    RNGO_REFLECT_END(glm::vec4)

    RNGO_REFLECT_BEGIN(glm::quat, Quat)
        RNGO_REFLECT_PROPERTY(glm::quat, x)
        RNGO_REFLECT_PROPERTY(glm::quat, y)
        RNGO_REFLECT_PROPERTY(glm::quat, z)
        RNGO_REFLECT_PROPERTY(glm::quat, w)
    RNGO_REFLECT_END(glm::quat)
}