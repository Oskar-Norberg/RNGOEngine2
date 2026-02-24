//
// Created by Oskar.Norberg on 2026-02-23.
//
#include "Asset/AssetLoader/Importers/ShaderImporter.h"

#include "Asset/AssetTypes/ShaderAsset.h"

namespace rngo
{
    void ShaderImporter::LoadFromDisk(AssetRegistry& registry, std::shared_ptr<AssetMetadata> metadata)
    {
    }

    std::shared_ptr<AssetMetadata> ShaderImporter::CreateTypedMetadataInstance(
        AssetHandle handle, std::filesystem::path relativePath
    ) const
    {
        return std::make_shared<ShaderAssetMetadata>(handle, relativePath);
    }

    AssetType ShaderImporter::GetAssociatedType() const
    {
        return AssetType::Shader;
    }

    std::span<const std::string_view> ShaderImporter::GetAssociatedExtensions() const
    {
        static constexpr std::array<std::string_view, 1> extensions = {".glsl"};
        return extensions;
    }
}