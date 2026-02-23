//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once

namespace rngo
{
    enum class AssetType
    {
        Model,
        Texture,
        Shader,
    };

    enum class AssetState
    {
        Invalid,
        Loading,
        Ready,
    };

    class Asset
    {
    public:
        Asset(const AssetType type, const AssetState state)
            : m_type(type), m_state(state)
        {
        }

        virtual ~Asset() = default;

    private:
        AssetType m_type;
        AssetState m_state;
    };
}