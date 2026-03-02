//
// Created by Oskar.Norberg on 2026-02-24.
//

#pragma once

#include <expected>
#include <filesystem>

namespace rngo::texture_loader
{
    enum class TextureLoadingError
    {
        FileNotFound,
        FailedToLoad,
    };

    using RawTexture = unsigned char;
    using RawTexturePtr = RawTexture*;
    struct TextureDataDeleter
    {
        void operator()(RawTexturePtr p) const;
    };
    using ManagedTextureDataType = std::unique_ptr<RawTexture, TextureDataDeleter>;

    struct TextureData
    {
        unsigned int Width;
        unsigned int Height;
        unsigned int NrChannels;

        ManagedTextureDataType Data;
    };

    std::expected<TextureData, TextureLoadingError> LoadTexture(const std::filesystem::path& path);
}