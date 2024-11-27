#pragma once

#include "Input.hpp" 
#include "Window.hpp"
#include <memory>

namespace eng{
    /**
     * @class Engine
     * @brief The core of the whole 3D engine
     *
     * This class is the main component of the 3D engine, 
     * implemented as a Singleton to ensure that only one instance
     * exists through the application's lifetime.
     */
    class Engine{
        private:
            Window window;
            Input inputHandler;
            static std::unique_ptr<Engine> eInstance; 

        private:
            Engine(const WindowSpec& windowSpec);                
            Engine(const Engine&) = delete;    
            Engine& operator=(const Engine&) = delete;

        public:
            /**
             * @brief Creates instance of the Engine if does not exist.
             */
            static void init(const WindowSpec& windowSpec);

            /**
             *@brief Gets the instance of the Engine class, creates one if does not exist.
             *@return Instance of the Engine.
             */
            static Engine& getInstance();
           
            /**
             * @brief Gets the window reference
             * @return Window reference
             */
            Window& getWindow();

            /**
             * @brief Gets the inputHandler reference
             * @return inputHandler reference
             */
            Input& getInputHandler();
    };
}
