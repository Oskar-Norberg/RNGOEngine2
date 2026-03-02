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
}