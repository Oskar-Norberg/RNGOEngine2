//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include <filesystem>

#include "Asset/Asset.h"

namespace rngo
{
    class AssetMetadata
    {
    public:
        explicit AssetMetadata(AssetHandle handle, std::filesystem::path relativePath)
            : m_handle(std::move(handle)), m_relativePath(std::move(relativePath))
        {
        }

        virtual ~AssetMetadata() = default;

        AssetHandle GetHandle() const
        {
            return m_handle;
        }

        const std::filesystem::path& GetRelativePath() const
        {
            return m_relativePath;
        }

    private:
        AssetHandle m_handle;
        std::filesystem::path m_relativePath;
    };
}