//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include <expected>
#include <filesystem>

#include "Asset/Asset.h"
#include "Asset/AssetLoader/Importers/AssetImporter.h"
#include "Importers/ModelImporter.h"
#include "Importers/ShaderImporter.h"
#include "Importers/TextureImporter.h"

namespace rngo
{
    class AssetFetcher;
    class AssetDatabase;
    class AssetRegistry;
}

namespace rngo
{
    enum class AssetImportErrorCode
    {
        AssetNotFound,
        AssetNotSupported,
    };

    class AssetLoader
    {
    public:
        AssetLoader(
            const AssetFetcher& assetFetcher, AssetDatabase& assetDatabase, AssetRegistry& assetRegistry
        );

    public:
        // Path relative to project root
        std::expected<AssetHandle, AssetImportErrorCode> ImportAsset(std::string_view relativePath);
        void RequestLoad(AssetHandle asset);

    private:
        const AssetFetcher& m_assetFetcher;
        AssetDatabase& m_assetDatabase;
        AssetRegistry& m_assetRegistry;

        std::tuple<TextureImporter, ModelImporter, ShaderImporter> m_importers;

    private:
        AssetImporter* GetAssetImporterForExtension(std::string_view extension);
    };
}