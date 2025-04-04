#include "Engine.hpp"
#include <memory>


namespace eng{
    std::unique_ptr<Engine> Engine::eInstance = nullptr;

    Engine::Engine(const WindowSpec& windowSpec) : window(windowSpec) {}
    
    void Engine::init(const WindowSpec& windowSpec){
        if(!eInstance)
            eInstance.reset(new Engine(windowSpec));
    }

    Engine& Engine::getInstance(){
        return *eInstance;
    }

    Window& Engine::getWindow(){
        return window;
    }

    Input& Engine::getInputHandler(){
        return inputHandler;
    }

    Renderer& Engine::getRenderer() {
        return renderer;
    }
}
