cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 23)
set(CORE_PROJECT_NAME RNGOEngine)
project(${CORE_PROJECT_NAME})

include(CMake/Dependencies.cmake)

# All individual EngineUnits
include(CMake/EngineUnits.cmake)

add_executable(${CORE_PROJECT_NAME}
        main.cpp
)
target_include_directories(${CORE_PROJECT_NAME} PUBLIC include)

target_link_libraries(${CORE_PROJECT_NAME} PUBLIC
        ${UTILITIES_PROJECT_NAME}
        ${LOGGING_PROJECT_NAME}

        ${ECS_PROJECT_NAME}
        ${SYSTEMS_PROJECT_NAME}
        ${COMPONENTS_PROJECT_NAME}
)


#target_compile_features(${CORE_PROJECT_NAME} PUBLIC cxx_std_23)