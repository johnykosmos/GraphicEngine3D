#include "Application.hpp"
#include "Engine.hpp"
#include <iostream>

namespace eng{
    Application::Application(){
        Engine::init(WindowSpec());
    }

    void Application::run(){
        Engine& eng = Engine::getInstance(); 
        Window& window = eng.getWindow();
        Input& input = eng.getInputHandler();
        
        while(!window.shouldWindowClose()){
            window.pollEvents();

            onUpdate();

            window.display();
                
        }
    }

}
