#pragma once

#include <GLFW/glfw3.h>


namespace eng {

    /**
     * @struct WindowResolution
     * @brief Window resolution.
     */
    struct WindowResolution {
        int width;
        int height;
    };

    /**
     * @struct WindowSpec
     * @brief Window specification.
     */
    struct WindowSpec{
        int height = 800;
        int width = 800;
        bool fullscreen = false;
        bool vsync = true;
        const char* title = "Engine Window";
    };

   /**
     * @class Window
     * @brief Window related actions.  
     *
     * This class represents window and performs related actions.
     */
    class Window{
        private:
            GLFWwindow *window; 
        
        public:
            /**
             * @brief Constructs a window with the given specification.
             * @param spec A const reference to WindowSpec struct containing 
             * the specification for the window.
             */
            Window(const WindowSpec& spec);

            /**
             * @brief Cleans up the window resources.
             */
            ~Window();
            
            /**
             * @brief Enables/disables the vsync
             * @param value A bool value representing vsync state
             */
            void setVsync(bool value);

            /**
             * @brief Gets window resolution
             * @return Struct of two ints representing the resolution
             */
             WindowResolution getResolution();

            /*
             * @brief Checks if window should close.
             * @return true if the window should close, false otherwise
             */
            bool shouldWindowClose();

            /*
             * @brief Displays the content.
             */
            void display();

            /*
             * @brief Process pending events.
             */
            void pollEvents();

    };
}
