//
// Created by Oskar.Norberg on 2026-02-23.
//

#include "Asset/AssetLoader/AssetLoader.h"

#include "Asset/AssetDatabase/AssetDatabase.h"
#include "Asset/AssetFetcher/AssetFetcher.h"
#include "Error/Error.h"
#include "Logging/Logger.h"

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
        const auto* importer = GetAssetImporterForExtension(assetExtension.string());

        if (!importer)
        {
            return std::unexpected(AssetImportErrorCode::AssetNotSupported);
        }

        AssetHandle handle{.UUID = GenerateUUID(), .Type = importer->GetAssociatedType()};

        auto metadata = importer->CreateTypedMetadataInstance(handle, relativePath);
        m_assetDatabase.Insert(std::move(metadata));

        return handle;
    }

    void AssetLoader::RequestLoad(const AssetHandle& asset)
    {
        auto* importerPtr = GetAssetImporterForType(asset.Type);

        if (!importerPtr)
        {
            RNGO_LOG(
                LogLevel::Critical, "Tried to import AssetHandle with invalid type: UUID({}), Type({})",
                asset.UUID.GetValue(), std::to_underlying(asset.Type)
            );
            return;
        }

        const auto metadataOpt = m_assetDatabase.Get(asset);
        if (!metadataOpt)
        {
            RNGO_LOG(
                LogLevel::Critical, "Tried to import AssetHandle with invalid handle: UUID({}), Type({})",
                asset.UUID.GetValue(), std::to_underlying(asset.Type)
            );
            return;
        }

        auto& metadata = metadataOpt.value();
        auto& importer = *importerPtr;

        importer.LoadFromDisk(metadata);
    }

    AssetImporter* AssetLoader::GetAssetImporterForExtension(const std::string_view extension)
    {
        AssetImporter* foundImporter = nullptr;

        std::apply(
            [&](auto&... importer)
            {
                ((
                     [&]
                     {
                         const auto supportedExtensions = importer.GetAssociatedExtensions();
                         for (const auto& supportedExtension : supportedExtensions)
                         {
                             if (extension == supportedExtension)
                             {
                                 foundImporter = &importer;
                                 return;
                             }
                         }
                     }()
                 ),
                 ...);
            },
            m_importers
        );

        return foundImporter;
    }

    AssetImporter* AssetLoader::GetAssetImporterForType(AssetType type)
    {
        // This should probably be cached somewhere.
        AssetImporter* foundImporter = nullptr;

        std::apply(
            [&](auto&... importer)
            {
                ((
                     [&]
                     {
                         if (importer.GetAssociatedType() == type)
                         {
                             foundImporter = &importer;
                             return;
                         }
                     }()
                 ),
                 ...);
            },
            m_importers
        );

        return foundImporter;
    }
}