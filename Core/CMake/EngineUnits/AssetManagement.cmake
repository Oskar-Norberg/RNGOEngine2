set(ASSET_MANAGEMENT_PROJECT_NAME RNGOEngine_AssetManagement)
add_library(${ASSET_MANAGEMENT_PROJECT_NAME} STATIC
        include/Asset/Asset.h
        include/Asset/AssetMetadata.h

        include/Asset/AssetLoader/AssetLoader.h
        src/Asset/AssetLoader/AssetLoader.cpp
        # AssetImporters
        include/Asset/AssetLoader/Importers/AssetImporter.h

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
