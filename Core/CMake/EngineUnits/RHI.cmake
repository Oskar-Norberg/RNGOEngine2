set(RHI_PROJECT_NAME RNGOEngine_RHI)
add_library(${RHI_PROJECT_NAME} STATIC
        include/Rendering/RHI/RenderFeatureBit.h
        include/Rendering/RHI/ClearTargetBit.h

        include/Rendering/RHI/Buffers.h
        include/Rendering/RHI/VertexArrayObject.h
        include/Rendering/RHI/Shader.h

        include/Rendering/RHI/IRHI.h

        include/Rendering/RHI/Implementation/OpenGLRHI.h
        src/Rendering/RHI/Implementation/OpenGLRHI.cpp
)
target_include_directories(${RHI_PROJECT_NAME} PUBLIC include)
target_link_libraries(${RHI_PROJECT_NAME} PUBLIC
        ${CORE_UTILS} glad
)
