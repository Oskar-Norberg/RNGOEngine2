//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include <unordered_map>

#include "Asset/Asset.h"
#include "Asset/AssetMetadata.h"

namespace rngo
{
    class AssetDatabase
    {
    public:
        void Insert(std::shared_ptr<AssetMetadata> metadata);

        std::optional<std::shared_ptr<AssetMetadata>> Find(const std::filesystem::path& relativePath);

    private:
        std::unordered_map<AssetHandle, std::shared_ptr<AssetMetadata>, AssetHandleHasher> m_handleToMetadata;
        std::unordered_map<std::filesystem::path, std::shared_ptr<AssetMetadata>> m_relativePathToMetadata;
    };
}