set(RHI_PROJECT_NAME RNGOEngine_RHI)
add_library(${RHI_PROJECT_NAME} STATIC
        include/Rendering/RHI/RenderFeature.h
        include/Rendering/RHI/ClearTarget.h

        include/Rendering/RHI/Buffers.h
        include/Rendering/RHI/VertexArrayObject.h
        include/Rendering/RHI/Shader.h

        include/Rendering/RHI/IRHI.h
)
target_include_directories(${RHI_PROJECT_NAME} PUBLIC include)
target_link_libraries(${RHI_PROJECT_NAME} PUBLIC
        ${CORE_UTILS}
)
