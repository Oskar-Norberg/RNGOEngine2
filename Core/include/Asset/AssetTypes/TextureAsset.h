//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include "Asset/AssetMetadata.h"
#include "AssetLoading/TextureLoader.h"

namespace rngo
{
    class TextureAsset : public Asset
    {
    public:
        TextureAsset(const AssetType type, const AssetState state, texture_loader::TextureData textureData)
            : Asset(type, state), m_textureData(std::move(textureData))
        {
        }

    public:
        const texture_loader::TextureData& GetTextureData() const
        {
            return m_textureData;
        }

    private:
        texture_loader::TextureData m_textureData;
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