set(ECS_PROJECT_NAME RNGOEngine_ECS)
add_library(${ECS_PROJECT_NAME} INTERFACE
        include/ECS/Entity.h
        include/ECS/World.h
)
target_include_directories(${ECS_PROJECT_NAME} INTERFACE include)
target_link_libraries(${ECS_PROJECT_NAME} INTERFACE
        ${CORE_UTILS}
        EnTT::EnTT
)
