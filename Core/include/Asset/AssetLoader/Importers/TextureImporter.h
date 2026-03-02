//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include "AssetImporter.h"

namespace rngo
{
    class TextureImporter : public AssetImporter
    {
    public:
        AssetLoadStatusCode LoadFromDisk(
            AssetRegistry& registry, const AssetFetcher& assetFetcher, std::shared_ptr<AssetMetadata> metadata
        ) override;

        std::shared_ptr<AssetMetadata> CreateTypedMetadataInstance(
            AssetHandle handle, std::filesystem::path relativePath
        ) const override;
        AssetType GetAssociatedType() const override;
        std::span<const std::string_view> GetAssociatedExtensions() const override;
    };
}
