//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <string_view>

namespace rngo
{
    enum class EventType
    {
        ExitRequested = 0,
        KeyPressed,
        KeyReleased,
        MouseButtonPressed,
        MouseButtonReleased,
        MousePosition,
    };

    class Event
    {
    public:
        virtual ~Event() = default;

        virtual EventType GetType() const = 0;
        virtual std::string_view GetName() const = 0;

        bool Handled = false;
    };
}

#define RNGO_EVENT_TYPE(type) \
static constexpr rngo::EventType GetStaticType() { return rngo::EventType::type; } \
rngo::EventType GetType() const override { return GetStaticType(); } \
static constexpr std::string_view GetStaticName() { return #type; } \
std::string_view GetName() const override { return GetStaticName(); }
