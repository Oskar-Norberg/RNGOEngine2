//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include <filesystem>

#include "Asset/AssetMetadata.h"
#include "Data/ThreadType.h"

namespace rngo
{
    class AssetImporter
    {
    public:
        virtual ~AssetImporter() = default;

        virtual void LoadFromDisk(std::shared_ptr<AssetMetadata> metadata) = 0;
        virtual void FinalizeLoad(ThreadType threadType) = 0;

    public:
        virtual std::shared_ptr<AssetMetadata> CreateTypedMetadataInstance(AssetHandle handle, std::filesystem::path relativePath) const = 0;
        virtual AssetType GetAssociatedType() const = 0;
        virtual std::span<const std::string_view> GetAssociatedExtensions() const = 0;
    };
}