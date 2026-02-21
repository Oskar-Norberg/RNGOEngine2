set(COMPONENTS_PROJECT_NAME RNGOEngine_Components)
add_library(${COMPONENTS_PROJECT_NAME} INTERFACE
        include/ECS/ComponentReflection.h
        include/ECS/Components.h
)
target_include_directories(${COMPONENTS_PROJECT_NAME} INTERFACE include)
target_link_libraries(${LOGGING_PROJECT_NAME} PUBLIC
        ${CORE_UTILS}
        glm::glm
)
