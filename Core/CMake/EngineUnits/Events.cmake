set(EVENTS_PROJECT_NAME RNGOEngine_Events)
add_library(${EVENTS_PROJECT_NAME} STATIC
        include/Events/Event.h
        include/Events/EngineEvents.h
        include/Events/EventQueue.h
        src/Events/EventQueue.cpp
)
target_include_directories(${EVENTS_PROJECT_NAME} PUBLIC include)
target_link_libraries(${EVENTS_PROJECT_NAME} PUBLIC
        ${CORE_UTILS}
)
