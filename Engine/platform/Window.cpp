#include "Engine.hpp"
#include "Keys.hpp"
#include <GLFW/glfw3.h>
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

        window = glfwCreateWindow(spec.width, spec.height, spec.title, NULL, NULL);
        if(!window){
            glfwTerminate();
            throw std::runtime_error("Failed to create a window!");
        
        }

        glfwMakeContextCurrent(window);

        glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);

        glfwSetKeyCallback(window, keyCallback);
    }

    Window::~Window(){
        if(window)
            glfwDestroyWindow(window);
        glfwTerminate();
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
