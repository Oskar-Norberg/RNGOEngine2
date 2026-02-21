set(RENDERING_API_PROJECT_NAME RNGOEngine_RenderingAPI)
add_library(${RENDERING_API_PROJECT_NAME} STATIC
        include/Rendering/RenderRunnable.h
        src/Rendering/RenderRunnable.cpp
)
target_include_directories(${RENDERING_API_PROJECT_NAME} PUBLIC include)
target_link_libraries(${RENDERING_API_PROJECT_NAME} PUBLIC
        ${PROFILING_PROJECT_NAME}
        ${UTILITIES_PROJECT_NAME}
        ${THREADING_PROJECT_NAME}
)
