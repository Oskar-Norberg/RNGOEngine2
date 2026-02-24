//
// Created by Oskar.Norberg on 2026-02-23.
//

#include "Asset/AssetLoader/Importers/ModelImporter.h"

#include "Asset/AssetTypes/ModelAsset.h"

namespace rngo
{
    void ModelImporter::LoadFromDisk(AssetRegistry& registry, std::shared_ptr<AssetMetadata> metadata)
    {
    }

    std::shared_ptr<AssetMetadata> ModelImporter::CreateTypedMetadataInstance(
        AssetHandle handle, std::filesystem::path relativePath
    ) const
    {
        return std::make_shared<ModelAssetMetadata>(handle, relativePath);
    }

    AssetType ModelImporter::GetAssociatedType() const
    {
        return AssetType::Model;
    }

    std::span<const std::string_view> ModelImporter::GetAssociatedExtensions() const
    {
        static constexpr std::array<std::string_view, 3> extensions = {".obj", ".fbx", ".gltf"};
        return extensions;
    }
}