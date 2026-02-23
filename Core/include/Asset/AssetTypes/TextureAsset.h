//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include "Asset/AssetMetadata.h"

namespace rngo
{
    class TextureAssetMetadata : public AssetMetadata
    {
    public:
        TextureAssetMetadata(AssetHandle handle, std::filesystem::path relativePath)
            : AssetMetadata(std::move(handle), std::move(relativePath))
        {
        }
    };
}