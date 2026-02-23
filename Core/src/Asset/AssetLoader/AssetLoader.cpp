//
// Created by Oskar.Norberg on 2026-02-23.
//

#include "Asset/AssetLoader/AssetLoader.h"

#include "Asset/AssetDatabase/AssetDatabase.h"
#include "Asset/AssetFetcher/AssetFetcher.h"

namespace rngo
{
    AssetLoader::AssetLoader(
        const AssetFetcher& assetFetcher, AssetDatabase& assetDatabase, AssetRegistry& assetRegistry
    )
        : m_assetFetcher(assetFetcher), m_assetDatabase(assetDatabase), m_assetRegistry(assetRegistry)

    {
    }

    std::expected<AssetHandle, AssetImportErrorCode> AssetLoader::ImportAsset(
        const std::string_view relativePath
    )
    {
        // TODO: Consider the case where /assets/grass.png and /assets/../assets/grass.png aren't evaluated as the same asset. (canonize rel-path)

        // TODO: Check that it isn't already registered.
        if (const auto foundMetadataOpt = m_assetDatabase.Find(relativePath); foundMetadataOpt)
        {
            return foundMetadataOpt.value()->GetHandle();
        }

        const auto fullPathOpt = m_assetFetcher.GetAssetPath(relativePath);

        if (!fullPathOpt)
        {
            return std::unexpected(AssetImportErrorCode::AssetNotFound);
        }

        const auto& fullPath = fullPathOpt.value();
        const auto assetExtension = fullPath.extension();
        auto* importer = GetAssetImporterForExtension(assetExtension.string());

        if (!importer)
        {
            return std::unexpected(AssetImportErrorCode::AssetNotSupported);
        }

        AssetHandle handle{.UUID = GenerateUUID(), .Type = importer->GetAssociatedType()};

        auto metadata = importer->CreateTypedMetadataInstance(handle, relativePath);
        m_assetDatabase.Insert(std::move(metadata));

        return handle;
    }

    void AssetLoader::RequestLoad(AssetHandle asset)
    {
    }

    AssetImporter* AssetLoader::GetAssetImporterForExtension(const std::string_view extension)
    {
        for (const auto& importer : m_importers)
        {
            const auto supportedExtensions = importer->GetAssociatedExtensions();
            for (const auto supportedExtension : supportedExtensions)
            {
                if (extension == supportedExtension)
                {
                    return importer.get();
                }
            }
        }

        return nullptr;
    }
}