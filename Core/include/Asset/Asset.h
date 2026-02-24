//
// Created by Oskar.Norberg on 2026-02-23.
//

#pragma once
#include "Utilities/Hashing.h"
#include "Utilities/UUID.h"

namespace rngo
{
    enum class AssetType
    {
        Model,
        Texture,
        Shader,
        // Material
    };

    enum class AssetState
    {
        Invalid,
        Loading,
        Ready,
        Consumed
    };

    class Asset
    {
    public:
        Asset(const AssetType type, const AssetState state)
            : m_type(type), m_state(state)
        {
        }

        virtual ~Asset() = default;

    public:
        AssetType GetType() const
        {
            return m_type;
        }

        void SetType(const AssetType type)
        {
            m_type = type;
        }

    public:
        AssetState GetState() const
        {
            return m_state;
        }

        void SetState(const AssetState state)
        {
            m_state = state;
        }

    private:
        AssetType m_type;
        AssetState m_state;
    };

    struct AssetHandle
    {
        UUID UUID;
        AssetType Type;

        bool operator==(const AssetHandle& other) const = default;
    };

    struct AssetHandleHasher
    {
        size_t operator()(const AssetHandle& handle) const
        {
            const auto uuidHash = UUIDHasher{}(handle.UUID);
            const auto typeHash = static_cast<size_t>(handle.Type);

            return hash::CombineHashes(uuidHash, typeHash);
        }
    };
}