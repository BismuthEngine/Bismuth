module;

#include <cstdint>

export module Fiber:FiberEvent;

export enum class FiberEventType : std::uint8_t {
    MouseButtonDown,
    MouseButton,
    MouseButtonUp,
    KeyDown,
    Key,
    KeyUp,
    CursorPosition,
    WindowResize,
    Scroll,
    Close,
    Maximize,
    Minimize,
    Restore,
    InputAxis
};

export class FiberEvent {
public:
    FiberEvent(FiberEventType eventType)
    : type(eventType)
    {
    }

    FiberEventType type;
};