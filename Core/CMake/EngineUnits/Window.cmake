set(WINDOW_PROJECT_NAME RNGOEngine_Window)
add_library(${WINDOW_PROJECT_NAME} STATIC
        include/Rendering/Window/IWindow.h

        include/Rendering/Window/GLFWWindow.h
        src/Rendering/Window/GLFWWindow.cpp
)
target_include_directories(${WINDOW_PROJECT_NAME} PUBLIC include)
target_link_libraries(${WINDOW_PROJECT_NAME} PUBLIC glad glfw)
target_link_libraries(${WINDOW_PROJECT_NAME} PUBLIC
        ${CORE_UTILS}
)
