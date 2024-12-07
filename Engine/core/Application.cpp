#include "glad/glad.h"
#include "Application.hpp"
#include "Engine.hpp"
#include <iostream>

void DebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity,
                            GLsizei length, const GLchar* message, const void* userParam)
{
    std::cerr << "OpenGL Debug Message:\n";
    std::cerr << "Source: " << source << "\n";
    std::cerr << "Type: " << type << "\n";
    std::cerr << "ID: " << id << "\n";
    std::cerr << "Severity: " << severity << "\n";
    std::cerr << "Message: " << message << "\n\n";
}

namespace eng{
    Application::Application(){
        Engine::init(WindowSpec());
    }

    void Application::run(){
        Engine& eng = Engine::getInstance(); 
        Window& window = eng.getWindow();
        
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallback(DebugCallback, nullptr);

        while(!window.shouldWindowClose()){
            window.pollEvents();

            onUpdate();

            window.display();
                
        }
    }

}
