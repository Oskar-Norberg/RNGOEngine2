//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include <memory>
#include <unordered_map>

#include "Asset/Asset.h"
#include "Utilities/UUID.h"

namespace rngo
{
    class AssetRegistry
    {
    public:

    private:
        std::unordered_map<UUID, std::shared_ptr<Asset>> m_assets;
    };
}