#include "Application.hpp"
#include "Engine.hpp"
#include "Keys.hpp"
#include "Window.hpp"
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

            window.display();
                
        }
    }

}
