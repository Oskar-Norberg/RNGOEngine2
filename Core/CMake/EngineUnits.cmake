include(CMake/EngineUnits/Utilities.cmake)
include(CMake/EngineUnits/Logging.cmake)

include(CMake/EngineUnits/ECS.cmake)
include(CMake/EngineUnits/Systems.cmake)

include(CMake/EngineUnits/Components.cmake)

list(APPEND ALL_ENGINE_UNITS
        ${UTILITIES_PROJECT_NAME}
        ${LOGGING_PROJECT_NAME}
        ${ECS_PROJECT_NAME}
        ${SYSTEMS_PROJECT_NAME}
        ${COMPONENTS_PROJECT_NAME}
)

set(ALL_ENGINE_UNITS "${ALL_ENGINE_UNITS}" PARENT_SCOPE)