#include "Application.hpp"
#include "Engine.hpp"
#include "Window.hpp"

namespace eng{
    Application::Application(){
        Engine::init(WindowSpec());
    }

    void Application::run(){
        Engine &eng = Engine::getInstance(); 
        Window &window = eng.getWindow();
        
        while(!window.shouldWindowClose()){
            window.display();
            window.pollEvents();
        }
    }

}
