//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include <memory>
#include <optional>
#include <unordered_map>

#include "Asset/Asset.h"

namespace rngo
{
    class AssetRegistry
    {
    public:
        void Insert(const AssetHandle& handle, const std::shared_ptr<Asset>& asset);
        void Remove(const AssetHandle& handle);

        std::optional<std::shared_ptr<const Asset>> Get(const AssetHandle& handle);

    private:
        std::mutex mutex;
        std::unordered_map<AssetHandle, std::shared_ptr<Asset>, AssetHandleHasher> m_assets;
    };
}