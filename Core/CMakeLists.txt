cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 23)
set(CORE_PROJECT_NAME RNGOEngine)
project(${CORE_PROJECT_NAME})

include(CMake/Dependencies.cmake)

# All individual EngineUnits
include(CMake/EngineUnits.cmake)

add_library(${CORE_PROJECT_NAME} STATIC
        include/Application.h
        src/Application.cpp
        include/EntryPoint.h
)
target_include_directories(${CORE_PROJECT_NAME} PUBLIC include)

target_link_libraries(${CORE_PROJECT_NAME} PUBLIC ${ALL_ENGINE_UNITS})
