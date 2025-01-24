#pragma once

#include "Scene.hpp"

namespace eng{
    /**
     * @class Application
     * @brief Main program loop
     *
     * This class is the frontend of the engine and should be a
     * base class for the application. It contains the main program
     * loop.
     */
    class Application{
        private:
            Scene* currentScene = nullptr;

        public:
            explicit Application();

            /**
             * @brief Is called on every main loop iteration
             */
            virtual void onUpdate() = 0;

            /**
             * @brief Sets the scene that will be rendered. 
             */
            void setScene(Scene& scene);

            /**
             * @brief Starts the main application loop 
             */
            void run();

    };
}
