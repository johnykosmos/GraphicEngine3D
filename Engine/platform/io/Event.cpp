#include "Event.hpp"
#include <cassert>


namespace eng {
    Event::Event(EventType type, KeyEvent key) : type(type), key(key) {}

    EventType Event::getEventType() const {
        return type;
    }

    KeyEvent Event::getKey() const {
        assert(type == EventType::KeyPressedEvent || type == EventType::KeyReleasedEvent);
        return key;
    }
} // namespace eng
