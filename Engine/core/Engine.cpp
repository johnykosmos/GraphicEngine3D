#include "Engine.hpp"
#include "Window.hpp"


namespace eng{
    Engine::Engine() : window(Window(WindowSpec())) {}

    Engine& Engine::getInstance(){
        static Engine instance; // it is only accessible within this function although created only once
        return instance;
    }
    
};
