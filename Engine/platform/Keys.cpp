#include "Keys.hpp"

namespace eng {
    bool translateGLFWKey(int key, Key &mappedKey){
            switch (key) {
                case GLFW_KEY_W: mappedKey = eng::Key::W; break;
                case GLFW_KEY_A: mappedKey = eng::Key::A; break;
                case GLFW_KEY_S: mappedKey = eng::Key::S; break;
                case GLFW_KEY_D: mappedKey = eng::Key::D; break;
                case GLFW_KEY_ESCAPE: mappedKey = eng::Key::Escape; break;
                case GLFW_KEY_SPACE: mappedKey = eng::Key::Space; break;
                case GLFW_KEY_ENTER: mappedKey = eng::Key::Enter; break;
                case GLFW_KEY_UP: mappedKey = eng::Key::Up; break;
                case GLFW_KEY_DOWN: mappedKey = eng::Key::Down; break;
                case GLFW_KEY_LEFT: mappedKey = eng::Key::Left; break;
                case GLFW_KEY_RIGHT: mappedKey = eng::Key::Right; break;
                default: return false;
            }
            return true;
        }
}
