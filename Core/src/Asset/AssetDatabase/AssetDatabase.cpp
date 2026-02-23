//
// Created by Oskar.Norberg on 2026-02-23.
//

#include "Asset/AssetDatabase/AssetDatabase.h"

namespace rngo
{
    void AssetDatabase::Insert(std::shared_ptr<AssetMetadata> metadata)
    {
        m_handleToMetadata.insert(std::make_pair(metadata->GetHandle(), metadata));
        m_relativePathToMetadata.insert(std::make_pair(metadata->GetRelativePath(), metadata));
    }

    std::optional<std::shared_ptr<AssetMetadata>> AssetDatabase::Find(
        const std::filesystem::path& relativePath
    )
    {
        if (const auto it = m_relativePathToMetadata.find(relativePath); it != m_relativePathToMetadata.end())
        {
            return it->second;
        }

        return std::nullopt;
    }
}