//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include "AssetImporter.h"

namespace rngo
{
    class ShaderImporter : public AssetImporter
    {
    public:
        void LoadFromDisk(std::shared_ptr<AssetMetadata> metadata) override;
        void FinalizeLoad(ThreadType threadType) override;

    public:
        std::shared_ptr<AssetMetadata> CreateTypedMetadataInstance(
            AssetHandle handle, std::filesystem::path relativePath
        ) const override;
        AssetType GetAssociatedType() const override;
        std::span<const std::string_view> GetAssociatedExtensions() const override;
    };
}
