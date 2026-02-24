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

        std::optional<std::shared_ptr<const Asset>> GetReady(const AssetHandle& handle);
        std::optional<std::shared_ptr<const Asset>> GetConsumed(const AssetHandle& handle);

        // TODO: This seems extremely naive, this will be huge and dynamically allocated.
        // This should probably take in a Functor and iterate over the list until it founds the correct assets.
        std::vector<std::shared_ptr<Asset>> GetAllReady();

    private:
        std::mutex mutex;
        std::unordered_map<AssetHandle, std::shared_ptr<Asset>, AssetHandleHasher> m_assets;

    private:
        std::optional<std::shared_ptr<const Asset>> GetAssetIfStateIs(const AssetHandle& handle, AssetState state);
    };
}