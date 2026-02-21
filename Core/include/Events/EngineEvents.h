//
// Created by ringo on 2026-02-21.
//

#pragma once

#include "Data/KeyCodes.h"
#include "Data/MouseCodes.h"
#include "Event.h"

namespace rngo
{
    class ExitRequestedEvent : public Event
    {
    public:
        RNGO_EVENT_TYPE(ExitRequested)
    };

    class KeyPressedEvent : public Event
    {
    public:
        RNGO_EVENT_TYPE(KeyPressed)
        KeyCode Key;
    };

    class KeyReleasedEvent : public Event
    {
    public:
        RNGO_EVENT_TYPE(KeyReleased)
        KeyCode Key;
    };

    class MouseButtonPressedEvent : public Event
    {
    public:
        RNGO_EVENT_TYPE(MouseButtonPressed)
        MouseCode Button;
    };

    class MouseButtonReleasedEvent : public Event
    {
    public:
        RNGO_EVENT_TYPE(MouseButtonReleased)
        MouseCode Button;
    };

    // NOTE: Records the absolute position in relation to the window, not a diff.
    class MousePositionEvent : public Event
    {
    public:
        RNGO_EVENT_TYPE(MousePosition)
        float X, Y;
    };
}