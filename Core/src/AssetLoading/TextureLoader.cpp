//
// Created by Oskar.Norberg on 2026-02-24.
//

#include "AssetLoading/TextureLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace rngo::texture_loader
{
    std::expected<TextureData, TextureLoadingError> LoadTexture(const std::filesystem::path& path)
    {
        int width, height, nrChannels;
        unsigned char* data = stbi_load(path.string().data(), &width, &height, &nrChannels, 0);

        if (!data || width <= 0 || height <= 0 || nrChannels <= 0)
        {
            return std::unexpected(TextureLoadingError::FailedToLoad);
        }

        return TextureData{
            static_cast<unsigned int>(width), static_cast<unsigned int>(height),
            static_cast<unsigned int>(nrChannels), data
        };
    }

    void FreeTexture(const TextureData& texture)
    {
        stbi_image_free(texture.data);
    }
}