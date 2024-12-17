#include <glad/glad.h>
#include "Engine.hpp"
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
    }
    else if(action == GLFW_RELEASE)
        input.setKeyPressed(mappedKey, false);
}

namespace eng{
    Window::Window(const WindowSpec& spec){
        if(!glfwInit())
            throw std::runtime_error("Failed to initialize GLFW");

        GLFWmonitor* primaryMonitor = NULL; 

        if (spec.fullscreen) {
            primaryMonitor = glfwGetPrimaryMonitor();
        }

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
    
    std::pair<int, int> Window::getResolution() {
        int width, height;
        glfwGetWindowSize(window, &width, &height);
        return std::make_pair(width, height);
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
