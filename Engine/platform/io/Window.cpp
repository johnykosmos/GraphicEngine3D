#include <glad/glad.h>
#include "Window.hpp"
#include "Engine.hpp"
#include "Event.hpp"
#include "GLFW/glfw3.h"
#include "Keys.hpp"
#include <iostream>

void framebufferSizeCallback(GLFWwindow* window, int width, int height){
        glViewport(0, 0, width, height);
    }

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods){
    eng::Input& input = eng::Engine::getInstance().getInputHandler();
    eng::Key mappedKey;
    if(!eng::translateGLFWKey(key, mappedKey)){
        return;
    }

    if(action == GLFW_PRESS){
        input.setKeyPressed(mappedKey, true);
        input.pushEvent(eng::Event(eng::EventType::KeyPressedEvent, eng::KeyEvent{mappedKey}));
    } else if(action == GLFW_RELEASE) {
        input.setKeyPressed(mappedKey, false);
        input.pushEvent(eng::Event(eng::EventType::KeyReleasedEvent, eng::KeyEvent{mappedKey}));
    }
}

namespace eng{
    Window::Window(const WindowSpec& spec){
        if(!glfwInit())
            throw std::runtime_error("Failed to initialize GLFW");

        GLFWmonitor* primaryMonitor = NULL; 

        if (spec.fullscreen) {
            primaryMonitor = glfwGetPrimaryMonitor();
        }

        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

        window = glfwCreateWindow(spec.width, spec.height, spec.title, primaryMonitor, NULL);
        if(!window){
            glfwTerminate();
            throw std::runtime_error("Failed to create a window!");
        }

        glfwMakeContextCurrent(window);
        setVsync(spec.vsync); 

         if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
            throw std::runtime_error("Failed to initialize GLAD");

        glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

        glfwSetKeyCallback(window, keyCallback);
    }

    Window::~Window(){
        if(window)
            glfwDestroyWindow(window);
        glfwTerminate();
    }

    void Window::setVsync(bool value){
        int interval = 0;
        if (value) {
            interval = 1;
        }
        glfwSwapInterval(interval);
    }
    
    WindowResolution Window::getResolution() {
        WindowResolution windowRes; 
        glfwGetWindowSize(window, &windowRes.width, &windowRes.height);
        return windowRes;
    }

    bool Window::shouldWindowClose(){
        return glfwWindowShouldClose(window);
    }
    
    void Window::display(){
        glfwSwapBuffers(window);
    }
    
    void Window::pollEvents(){
        glfwPollEvents();
    }
}
