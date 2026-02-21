//
// Created by ringo on 2026-02-21.
//

#include "Events/EventQueue.h"

#include <algorithm>

namespace rngo
{
    std::span<const std::unique_ptr<Event>> EventQueue::GetEvents()
    {
        return m_events;
    }

    void EventQueue::PopHandledEvents()
    {
        const auto newEnd = std::ranges::remove_if(
                                m_events,
                                [](const std::unique_ptr<Event>& event)
                                {
                                    return event->Handled;
                                }
        ).begin();

        m_events.erase(newEnd, m_events.end());
    }
}