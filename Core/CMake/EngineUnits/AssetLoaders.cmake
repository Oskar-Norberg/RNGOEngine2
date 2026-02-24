set(ASSET_LOADERS_PROJECT_NAME RNGOEngine_AssetLoaders)
add_library(${ASSET_LOADERS_PROJECT_NAME} STATIC
        include/AssetLoading/TextureLoader.h
        src/AssetLoading/TextureLoader.cpp
)
target_include_directories(${ASSET_LOADERS_PROJECT_NAME} PUBLIC include)
target_link_libraries(${ASSET_LOADERS_PROJECT_NAME} PUBLIC
        ${CORE_UTILS} stb_image
)
