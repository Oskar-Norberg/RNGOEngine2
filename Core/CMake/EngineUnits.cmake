include(CMake/EngineUnits/Utilities.cmake)
include(CMake/EngineUnits/Logging.cmake)
include(CMake/EngineUnits/Error.cmake)
include(CMake/EngineUnits/Data.cmake)

# Interface to include to inherit all utils
set(CORE_UTILS RNGOEngine_CoreUtils)
add_library(${CORE_UTILS} INTERFACE)
target_link_libraries(${CORE_UTILS} INTERFACE
        ${LOGGING_PROJECT_NAME}
        ${UTILITIES_PROJECT_NAME}
        ${ERROR_PROJECT_NAME}
        ${DATA_PROJECT_NAME}
)

include(CMake/EngineUnits/Threading.cmake)
include(CMake/EngineUnits/Events.cmake)

include(CMake/EngineUnits/ECS.cmake)
include(CMake/EngineUnits/Systems.cmake)

include(CMake/EngineUnits/Components.cmake)

include(CMake/EngineUnits/AssetLoaders.cmake)
include(CMake/EngineUnits/AssetManagement.cmake)

include(CMake/EngineUnits/Window.cmake)
include(CMake/EngineUnits/RHI.cmake)
include(CMake/EngineUnits/RenderingAPI.cmake)

list(APPEND ALL_ENGINE_UNITS
        ${UTILITIES_PROJECT_NAME}
        ${LOGGING_PROJECT_NAME}
        ${ERROR_PROJECT_NAME}

        ${THREADING_PROJECT_NAME}
        ${EVENTS_PROJECT_NAME}

        ${ECS_PROJECT_NAME}
        ${SYSTEMS_PROJECT_NAME}

        ${COMPONENTS_PROJECT_NAME}

        ${ASSET_LOADERS_PROJECT_NAME}
        ${ASSET_MANAGEMENT_PROJECT_NAME}

        ${WINDOW_PROJECT_NAME}
        ${RHI_PROJECT_NAME}
        ${RENDERING_API_PROJECT_NAME}
)

set(ALL_ENGINE_UNITS "${ALL_ENGINE_UNITS}" PARENT_SCOPE)