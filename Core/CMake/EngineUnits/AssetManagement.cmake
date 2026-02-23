set(ASSET_MANAGEMENT_PROJECT_NAME RNGOEngine_AssetManagement)
add_library(${ASSET_MANAGEMENT_PROJECT_NAME} STATIC
        include/Asset/Asset.h
        include/Asset/AssetMetadata.h

        # Asset Types
        include/Asset/AssetTypes/ModelAsset.h
        include/Asset/AssetTypes/TextureAsset.h
        include/Asset/AssetTypes/ShaderAsset.h

        include/Asset/AssetLoader/AssetLoader.h
        src/Asset/AssetLoader/AssetLoader.cpp
        # AssetImporters
        include/Asset/AssetLoader/Importers/AssetImporter.h
        ## Implementations
        include/Asset/AssetLoader/Importers/ModelImporter.h
        src/Asset/AssetLoader/Importers/ModelImporter.cpp
        include/Asset/AssetLoader/Importers/ShaderImporter.h
        src/Asset/AssetLoader/Importers/ShaderImporter.cpp
        include/Asset/AssetLoader/Importers/TextureImporter.h
        src/Asset/AssetLoader/Importers/TextureImporter.cpp

        include/Asset/AssetFetcher/AssetFetcher.h
        src/Asset/AssetFetcher/AssetFetcher.cpp

        include/Asset/AssetDatabase/AssetDatabase.h
        src/Asset/AssetDatabase/AssetDatabase.cpp
        include/Asset/AssetRegistry/AssetRegistry.h
        src/Asset/AssetRegistry/AssetRegistry.cpp
)
target_include_directories(${ASSET_MANAGEMENT_PROJECT_NAME} PUBLIC include)
target_link_libraries(${ASSET_MANAGEMENT_PROJECT_NAME} PUBLIC
        ${CORE_UTILS}
)
