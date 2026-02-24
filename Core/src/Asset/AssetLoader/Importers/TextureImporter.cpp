//
// Created by Oskar.Norberg on 2026-02-23.
//

#include "Asset/AssetLoader/Importers/TextureImporter.h"

#include <iostream>

#include "Asset/AssetTypes/TextureAsset.h"
#include "AssetLoading/TextureLoader.h"
#include "Error/Error.h"

namespace rngo
{
    AssetLoadStatusCode TextureImporter::LoadFromDisk(
        AssetRegistry& registry, const AssetFetcher& assetFetcher, std::shared_ptr<AssetMetadata> metadata
    )
    {
        const auto fullPathOpt = assetFetcher.GetAssetPath(metadata->GetRelativePath().string());
        if (!fullPathOpt)
        {
            return AssetLoadStatusCode::AssetNotFound;
        }
        const auto& path = fullPathOpt.value();

        const auto textureDataResult = texture_loader::LoadTexture(path);

        if (!textureDataResult)
        {
            switch (textureDataResult.error())
            {
                case texture_loader::TextureLoadingError::FileNotFound:
                    return AssetLoadStatusCode::AssetNotFound;
                case texture_loader::TextureLoadingError::FailedToLoad:
                    return AssetLoadStatusCode::MalformedAsset;
                default:
                    return AssetLoadStatusCode::AssetNotFound;
            }
        }

        const auto& textureData = textureDataResult.value();

        const auto texture =
            std::make_shared<TextureAsset>(AssetType::Texture, AssetState::Ready, textureData);
        registry.Insert(metadata->GetHandle(), texture);

        return AssetLoadStatusCode::Success;
    }

    void TextureImporter::UnloadFromDisk(const std::shared_ptr<Asset> asset)
    {
        const auto textureAsset = std::dynamic_pointer_cast<TextureAsset>(asset);
        if (!textureAsset)
        {
            RNGO_FATAL_ERROR("Type mismatch on TextureAsset");
        }
        rngo::texture_loader::FreeTexture(textureAsset->GetTextureData());

        // TODO: Store TextureData as an optional field?
        textureAsset->SetTextureData(texture_loader::TextureData{});
        asset->SetState(AssetState::Consumed);
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