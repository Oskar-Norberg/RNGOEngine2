//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include "Asset/AssetMetadata.h"

namespace rngo
{
    class ShaderAssetMetadata : public AssetMetadata
    {
    public:
        ShaderAssetMetadata(AssetHandle handle, std::filesystem::path relativePath)
            : AssetMetadata(std::move(handle), std::move(relativePath))
        {
        }
    };
}