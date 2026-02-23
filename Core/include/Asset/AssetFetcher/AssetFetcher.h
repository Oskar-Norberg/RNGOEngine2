//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

#include <filesystem>

namespace rngo
{
    // TODO: Strongly typed class for RelativePath?

    // Fetches paths relative to project path
    // E.g "/home/user/Project/Textures/Grass.png" would be fetched using "Textures/Grass.png".
    class AssetFetcher
    {
    public:
        AssetFetcher(const std::filesystem::path& projectPath);

        // Fetches using relative path, returns absolute path.
        std::optional<std::filesystem::path> GetAssetPath(std::string_view relativePath);

        // Gets relative path from an absolute path, nullopt if path is outside ProjectPath.
        std::optional<std::filesystem::path> GetRelativePath(const std::filesystem::path& fullPath);

    private:
        std::filesystem::path m_projectPath;
    };
}