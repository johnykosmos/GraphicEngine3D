#pragma once


#include "Camera.hpp"
#include "Entity.hpp"
#include "Light.hpp"
#include "Material.hpp"
#include <vector>


namespace eng {

    /**
     * @struct Drawable
     * @brief Stores the entity and related material.
     */
    struct Drawable{
        const Entity* entity;
        const Material* material;
    };

    /**
     * @class Scene
     * @brief Manages the collection of lights, drawables, and the active camera in a 3D scene.
     * 
     * The Scene class provides methods to add, remove, and retrieve light sources 
     * and drawable entities in the scene. It also manages the active camera, 
     * which is used for rendering and scene transformations. The Scene serves 
     * as a central container for all objects and components that are rendered 
     * or used during rendering.
     */
    class Scene {
        private:
            /**
             * @brief List of lights in the scene.
             */
            std::vector<Light*> lightList;

            /**
             * @brief List of drawables in the scene.
             */
            std::vector<Drawable> drawables;

            /**
             * @brief Pointer to the active camera.
             */
            Camera* activeCamera;

        protected:
            /**
             * @brief Adds a new light to the scene.
             * 
             * This method inserts a light source into the scene's light list.
             * It allows the renderer to access and use this light during rendering.
             * 
             * @param light The light source to be added.
             */
            void addLight(Light* light);

            /**
             * @brief Clears the light list.
             * 
             * This method removes all light sources from the scene's light list.
             * It effectively resets the collection of lights in the scene.
             */
            void clearLightList();

            /**
             * @brief Adds a new drawable entity to the scene.
             * 
             * This method inserts an entity and it's material into the scene's drawable list.
             * It allows the renderer to access and use this entity during rendering.
             * 
             * @param entity The entity to be added.
             * @param material The material of the entity
             */
            void addDrawable(const Entity& entity, const Material& material);

            /**
             * @brief Clears the drawables list.
             * 
             * This method removes all drawables from the scene's drawables list.
             */
            void clearDrawables();

            /**
             * @brief Sets the active camera for the scene.
             * 
             * This method allows the user to specify which camera should be considered 
             * the active camera in the scene. The active camera will be used for rendering 
             * and scene transformations.
             */
            void setActiveCamera(Camera& camera);

        public:
           /**
            * @brief Is called on every main loop iteration if scene is loaded.
            */
            virtual void onUpdate() = 0;

            /**
             * @brief Retrieves the list of lights in the scene.
             * 
             * This method returns a constant reference to the vector containing all 
             * the light sources in the scene. It can be used for querying the lights 
             * without modifying the list.
             * 
             * @return A constant reference to the vector containing pointers to all the light sources.
             */
            const std::vector<Light*>& getLightList() const;

            /**
             * @brief Retrieves the list of drawables in the scene.
             * 
             * This method returns a constant reference to the vector containing all 
             * the drawables in the scene.              * 
             * @return A constant reference to the vector containing all the 
             * drawables.
             */
            const std::vector<Drawable>& getDrawables() const;

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
