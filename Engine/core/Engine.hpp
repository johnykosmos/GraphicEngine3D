#pragma once

#include "Window.hpp"

namespace eng{
    /**
     * @class Engine
     * @brief The core of the whole 3D engine
     *
     * This class is the main component of the 3D engine, 
     * implemented as a Signleton to ensure that only one instance
     * exists through the application's lifetime.
     */
    class Engine{
        private:
            Window window;

        private:
            Engine();                
            ~Engine() = default;               
            Engine(const Engine&) = delete;    
            Engine& operator=(const Engine&) = delete;

        public:
            /**
             *@brief Gets the instance of the Engine class, creates one if does not exist.
             *@return Instance of the Engine.
             */
            static Engine& getInstance();
    };
}
