#pragma once

#include <GLFW/glfw3.h>

namespace eng{
    enum class Key {
        W       = GLFW_KEY_W,
        A       = GLFW_KEY_A,
        S       = GLFW_KEY_S,
        D       = GLFW_KEY_D,
        Escape  = GLFW_KEY_ESCAPE,
        Space   = GLFW_KEY_SPACE,
        Enter   = GLFW_KEY_ENTER,
        Up      = GLFW_KEY_UP,
        Down    = GLFW_KEY_DOWN,
        Left    = GLFW_KEY_LEFT,
        Right   = GLFW_KEY_RIGHT
    };

    enum class MouseButton {
        Left    = GLFW_MOUSE_BUTTON_LEFT,
        Right   = GLFW_MOUSE_BUTTON_RIGHT,
        Middle  = GLFW_MOUSE_BUTTON_MIDDLE
    };

    const Key keyEnumeration[] = {
        Key::W, Key::A, Key::S, Key::D, Key::Escape, Key::Space, 
        Key::Enter, Key::Up, Key::Down, Key::Left, Key::Right
    };
    
    /**
     * @brief Translates GLFW keycoding to Engine keycoding
     * @param key GLFW keycode
     * @param mappedKey A reference to the Key variable that will hold the translation.
     * @return true if succeed, false if not
     */
    bool translateGLFWKey(int key, Key &mappedKey);
}
