set(SYSTEMS_PROJECT_NAME RNGOEngine_Systems)
add_library(${SYSTEMS_PROJECT_NAME} INTERFACE
        include/ECS/Systems/SystemContext.h
        include/ECS/Systems/SystemScheduler.h
)
target_include_directories(${SYSTEMS_PROJECT_NAME} INTERFACE include)
target_link_libraries(${SYSTEMS_PROJECT_NAME} INTERFACE
        ${CORE_UTILS}
        ${ECS_PROJECT_NAME}
)


