//
// Created by Oskar.Norberg on 2026-02-23.
//

#include "Asset/AssetLoader/Importers/TextureImporter.h"

#include <iostream>

#include "Asset/AssetTypes/TextureAsset.h"

namespace rngo
{
    void TextureImporter::LoadFromDisk(AssetRegistry& registry, std::shared_ptr<AssetMetadata> metadata)
    {
        std::cout << "pretend this is loading from the disk" << std::endl;

        const auto texture = std::make_shared<TextureAsset>(AssetType::Texture, AssetState::Ready);
        registry.Insert(metadata->GetHandle(), texture);
    }

    std::shared_ptr<AssetMetadata> TextureImporter::CreateTypedMetadataInstance(
        AssetHandle handle, std::filesystem::path relativePath
    ) const
    {
        return std::make_shared<TextureAssetMetadata>(handle, relativePath);
    }

    AssetType TextureImporter::GetAssociatedType() const
    {
        return AssetType::Texture;
    }

    std::span<const std::string_view> TextureImporter::GetAssociatedExtensions() const
    {
        static constexpr std::array<std::string_view, 3> extensions = {".png", ".jpg", ".jpeg"};
        return extensions;
    }
}