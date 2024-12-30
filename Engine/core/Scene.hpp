#pragma once


#include "Camera.hpp"
#include "Light.hpp"
#include <memory>
#include <vector>


namespace eng {
    /**
     * @class Scene
     * @brief Manages the collection of lights in a 3D scene.
     * 
     * The Scene class provides methods to add, remove, and retrieve light sources 
     * in the scene. It serves as a container for all light sources that the 
     * renderer will use to compute lighting effects during rendering.
     */
    class Scene {
        private:
            /**
             * @brief List of lights in the scene.
             */
            std::vector<Light> lightList;

            /**
             * @brief Pointer to the active camera.
             */
            Camera* activeCamera;

        public:
            /**
             * @brief Adds a new light to the scene.
             * 
             * This method inserts a light source into the scene's light list.
             * It allows the renderer to access and use this light during rendering.
             * 
             * @param light The light source to be added.
             */
            void addLight(const Light& light);

            /**
             * @brief Clears the light list.
             * 
             * This method removes all light sources from the scene's light list.
             * It effectively resets the collection of lights in the scene.
             */
            void clearLightList();

            /**
             * @brief Retrieves the list of lights in the scene.
             * 
             * This method returns a constant reference to the vector containing all 
             * the light sources in the scene. It can be used for querying the lights 
             * without modifying the list.
             * 
             * @return A constant reference to the vector containing pointers to all the light sources.
             */
            const std::vector<Light>& getLightList() const;

            /**
             * @brief Sets the active camera for the scene.
             * 
             * This method allows the user to specify which camera should be considered 
             * the active camera in the scene. The active camera will be used for rendering 
             * and scene transformations.
             */
            void setActiveCamera(Camera& camera);

            /**
             * @brief Retrieves the active camera in the scene.
             * 
             * This method returns the pointer to the active camera in the scene, which 
             * is used for rendering. If no active camera is set, this method may return `nullptr`.
             * 
             * @return A pointer to the active camera in the scene.
             */
            Camera* getActiveCamera() const;
    };


} // namespace eng
