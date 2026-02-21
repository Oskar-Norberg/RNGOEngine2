set(THREADING_PROJECT_NAME RNGOEngine_Threading)
add_library(${THREADING_PROJECT_NAME} INTERFACE
        include/Rendering/Window/IWindow.h
)
target_include_directories(${THREADING_PROJECT_NAME} INTERFACE include)
target_link_libraries(${THREADING_PROJECT_NAME} INTERFACE
        ${LOGGING_PROJECT_NAME}
        ${PROFILING_PROJECT_NAME}
        ${UTILITIES_PROJECT_NAME}
)
