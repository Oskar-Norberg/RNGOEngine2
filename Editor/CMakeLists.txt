cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 23)

set(EDITOR_PROJECT_NAME RNGOEngine_Editor)
project(${EDITOR_PROJECT_NAME})

# Include Engine Core
add_subdirectory(
        ${CMAKE_CURRENT_SOURCE_DIR}/../Core
        ${CMAKE_CURRENT_BINARY_DIR}/Core
)

add_executable(${EDITOR_PROJECT_NAME} main.cpp
        include/Editor.h
        src/Editor.cpp
)

target_include_directories(${EDITOR_PROJECT_NAME} PUBLIC include)
target_link_libraries(${EDITOR_PROJECT_NAME} RNGOEngine)
