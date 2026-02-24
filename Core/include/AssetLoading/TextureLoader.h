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

    struct TextureData
    {
        unsigned int width;
        unsigned int height;
        unsigned int nrChannels;

        // TODO: Wrap in unique ptr.
        unsigned char* data;
    };

    std::expected<TextureData, TextureLoadingError> LoadTexture(const std::filesystem::path& path);
    void FreeTexture(const TextureData& texture);
}