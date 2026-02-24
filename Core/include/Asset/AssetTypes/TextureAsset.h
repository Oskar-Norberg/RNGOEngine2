//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include "Asset/AssetMetadata.h"

namespace rngo
{
    class TextureAsset : public Asset
    {
    public:
        TextureAsset(const AssetType type, const AssetState state)
            : Asset(type, state)
        {
        }
    };

    class TextureAssetMetadata : public AssetMetadata
    {
    public:
        TextureAssetMetadata(AssetHandle handle, std::filesystem::path relativePath)
            : AssetMetadata(std::move(handle), std::move(relativePath))
        {
        }
    };
}