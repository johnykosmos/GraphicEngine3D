#pragma once

#include <map>
#include "Keys.hpp"


namespace eng {
    
    /*
     * @class Input
     * @brief Input handler for mouse and keyboard events.
     *
     * This class handles the input from mouse and keyboard. It
     * stores states of every key.
     */
    class Input{
        private:
            static std::map<Key, bool> keyStates; 

        public:
            Input();

            /**
             * @brief Checks if key is pressed.
             * @return true if pressed, false if not.
             */
            bool isKeyPressed(Key key);

            /**
             * @brief Sets bool value for a specified key.
             * @param key A key to set.
             * @param value A bool value; true if pressed, false if not.
             */
            void setKeyPressed(Key key, bool value);
    };
}
