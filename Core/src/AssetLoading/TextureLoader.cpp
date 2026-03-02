//
// Created by Oskar.Norberg on 2026-02-24.
//

#include "AssetLoading/TextureLoader.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace rngo::texture_loader
{
    void TextureDataDeleter::operator()(const RawTexturePtr p) const
    {
        stbi_image_free(p);
    }

    std::expected<TextureData, TextureLoadingError> LoadTexture(const std::filesystem::path& path)
    {
        int width, height, nrChannels;
        unsigned char* data = stbi_load(path.string().data(), &width, &height, &nrChannels, 0);

        if (!data || width <= 0 || height <= 0 || nrChannels <= 0)
        {
            return std::unexpected(TextureLoadingError::FailedToLoad);
        }

        auto uniqueWrapper = std::unique_ptr<RawTexture, TextureDataDeleter>(data, TextureDataDeleter{});

        return TextureData{
            static_cast<unsigned int>(width), static_cast<unsigned int>(height),
            static_cast<unsigned int>(nrChannels), std::move(uniqueWrapper)
        };
    }
}