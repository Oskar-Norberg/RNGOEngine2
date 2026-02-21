//
// Created by ringo on 2026-02-21.
//

#pragma once

#include <concepts>
#include <memory>
#include <span>
#include <vector>

#include "Event.h"

namespace rngo
{
    class EventQueue
    {
    public:
        template<std::derived_from<Event> TEvent, typename... Args>
        void EmplaceEvent(Args&&... args);

        std::span<const std::unique_ptr<Event>> GetEvents();
        void PopHandledEvents();

    private:
        std::vector<std::unique_ptr<Event>> m_events;
    };

#include "EventQueue.inl"
}
