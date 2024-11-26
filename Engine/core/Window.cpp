#include "Window.hpp"
#include <GLFW/glfw3.h>
#include <iostream>

void framebufferSizeCallback(GLFWwindow* window, int width, int height){
        glViewport(0, 0, width, height);
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
