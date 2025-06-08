#pragma once

#include "Keys.hpp"

namespace eng {
    
    enum class EventType : int {
        None,
        KeyPressedEvent,
        KeyReleasedEvent
    };

    struct KeyEvent {
        Key keyCode;
    };

    class Event {
        private: 
            EventType type;
            union {
                KeyEvent key;
            };

        public:
            Event() = default;
            Event(EventType type, KeyEvent key);
            EventType getEventType() const;
            KeyEvent getKey() const;
    };

} // namespace eng
