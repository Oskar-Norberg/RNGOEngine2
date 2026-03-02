//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include <filesystem>

#include "Asset/Asset.h"
#include "Asset/AssetFetcher/AssetFetcher.h"
#include "Asset/AssetMetadata.h"
#include "Asset/AssetRegistry/AssetRegistry.h"

namespace rngo
{
    enum class AssetLoadStatusCode
    {
        Success,
        AssetNotFound,
        UnsupportedFormat,
        MalformedAsset,
        UnknownAsset
    };

    class AssetImporter
    {
    public:
        virtual ~AssetImporter() = default;

        virtual AssetLoadStatusCode LoadFromDisk(
            AssetRegistry& registry, const AssetFetcher& assetFetcher, std::shared_ptr<AssetMetadata> metadata
        ) = 0;

    public:
        virtual std::shared_ptr<AssetMetadata> CreateTypedMetadataInstance(
            AssetHandle handle, std::filesystem::path relativePath
        ) const = 0;
        virtual AssetType GetAssociatedType() const = 0;
        virtual std::span<const std::string_view> GetAssociatedExtensions() const = 0;
    };
}