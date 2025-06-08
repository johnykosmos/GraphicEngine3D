#include "Input.hpp"
#include "Keys.hpp"
#include <iostream>


namespace eng {
    std::map<Key, bool> Input::keyStates;
    std::queue<Event> Input::eventQueue; 

    Input::Input() {
       for (const auto& key : keyEnumeration) {
            keyStates[key] = false;
        } 
    }

   bool Input::isKeyPressed(Key key) {
        return keyStates.at(key); 
    }

    void Input::setKeyPressed(Key key, bool value) {
        keyStates[key] = value;
    }

    void Input::pushEvent(Event event) {
        eventQueue.push(event);
    }

    bool Input::pollEvents(Event& event) {
        if (eventQueue.empty()) {
            return false;
        }

        event = eventQueue.front();
        eventQueue.pop();
        return true;
    }
}
