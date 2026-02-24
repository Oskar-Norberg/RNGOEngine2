//
// Created by Oskar.Norberg on 2026-02-23.
//

#include "Asset/AssetRegistry/AssetRegistry.h"

namespace rngo
{
    void AssetRegistry::Insert(const AssetHandle& handle, const std::shared_ptr<Asset>& asset)
    {
        std::lock_guard<std::mutex> lock(mutex);

        // TODO: Override?
        m_assets.insert({handle, asset});
    }

    void AssetRegistry::Remove(const AssetHandle& handle)
    {
        std::lock_guard<std::mutex> lock(mutex);

        // Return bool?
        if (const auto it = m_assets.find(handle); it != m_assets.end())
        {
            m_assets.erase(it);
        }
    }

    std::optional<std::shared_ptr<const Asset>> AssetRegistry::Get(const AssetHandle& handle)
    {
        std::lock_guard<std::mutex> lock(mutex);

        if (const auto it = m_assets.find(handle); it != m_assets.end())
        {
            return it->second;
        }

        return std::nullopt;
    }

    std::optional<std::shared_ptr<const Asset>> AssetRegistry::GetReady(const AssetHandle& handle)
    {
        return GetAssetIfStateIs(handle, AssetState::Ready);
    }

    std::optional<std::shared_ptr<const Asset>> AssetRegistry::GetConsumed(const AssetHandle& handle)
    {
        return GetAssetIfStateIs(handle, AssetState::Consumed);
    }

    std::vector<std::shared_ptr<Asset>> AssetRegistry::GetAllReady()
    {
        std::lock_guard<std::mutex> lock(mutex);

        std::vector<std::shared_ptr<Asset>> readyAssets;
        for (const auto [handle, asset] : m_assets)
        {
            if (asset->GetState() == AssetState::Ready)
            {
                readyAssets.push_back(asset);
            }
        }

        return readyAssets;
    }

    std::optional<std::shared_ptr<const Asset>> AssetRegistry::GetAssetIfStateIs(
        const AssetHandle& handle, const AssetState state
    )
    {
        const auto assetOpt = Get(handle);

        if (assetOpt)
        {
            if (assetOpt->get()->GetState() == state)
            {
                return assetOpt.value();
            }
        }

        return std::nullopt;
    }
}