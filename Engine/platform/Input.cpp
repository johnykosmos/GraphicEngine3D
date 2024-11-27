#include "Input.hpp"
#include "Keys.hpp"
#include <iostream>


namespace eng {
    std::map<Key, bool> Input::keyStates;

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
}
