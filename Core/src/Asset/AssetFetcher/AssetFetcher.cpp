//
// Created by Oskar.Norberg on 2026-02-23.
//

#include "Asset/AssetFetcher/AssetFetcher.h"

namespace rngo
{
    AssetFetcher::AssetFetcher(const std::filesystem::path& projectPath)
        : m_projectPath(projectPath)
    {
    }

    std::optional<std::filesystem::path> AssetFetcher::GetAssetPath(const std::string_view relativePath) const
    {
        const auto fullPath = m_projectPath / relativePath;
        if (!std::filesystem::exists(fullPath))
        {
            return std::nullopt;
        }

        return fullPath;
    }

    std::optional<std::filesystem::path> AssetFetcher::GetRelativePath(
        const std::filesystem::path& fullPath
    ) const
    {
        const auto canonicalFullPath = std::filesystem::weakly_canonical(fullPath);
        const auto canonicalProjectPath = std::filesystem::weakly_canonical(m_projectPath);

        auto relative = std::filesystem::relative(canonicalFullPath, canonicalProjectPath);

        if (relative.empty() || relative.string().starts_with(".."))
            return std::nullopt;

        return relative;
    }
}