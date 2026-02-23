//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include <expected>
#include <filesystem>

#include "Asset/Asset.h"
#include "Asset/AssetLoader/Importers/AssetImporter.h"

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

        // TODO: This should defo be a tuple, but tuples look so shit to iterate over :sob:
        std::array<std::unique_ptr<AssetImporter>, 3> m_importers{
            nullptr
            /*
            std::make_unique<TextureImporter>(),
            std::make_unique<ModelImporter>(),
            std::make_unique<ShaderImporter>(),
            */
        };

    private:
        AssetImporter* GetAssetImporterForExtension(std::string_view extension);
    };
}