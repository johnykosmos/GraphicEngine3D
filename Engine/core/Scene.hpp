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
            * @brief List of point lights in the scene.
            */
            std::vector<PointLight*> pointLightList;        

            /**
             * @brief List of point lights in the scene.
             */
            std::vector<DirectionalLight*> directionalLightList;

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
             * @brief Adds a new directional light to the scene.
             * 
             * This method inserts a directional light source into the scene's light list.
             * It allows the renderer to access and use this light during rendering.
             * 
             * @param light The light source to be added.
             */
            void addLight(DirectionalLight& light);

            /**
             * @overload
             * @brief Adds a new point light to the scene.
             * 
             * This method inserts a point light source into the scene's light list.
             * It allows the renderer to access and use this light during rendering.
             * 
             * @param light The light source to be added.
             */
            void addLight(PointLight& light);

            /**
             * @brief Removes a point light from the scene.
             * 
             * This method removes a point light source from the scene's light list.
             * It ensures that the renderer no longer uses this light during rendering.
             * 
             * @param light The light source to be removed.
             */
            void removeLight(PointLight& light);

            /**
             * @overload
             * @brief Removes a directional light from the scene.
             * 
             * This method removes a directional light source from the scene's light list.
             * It ensures that the renderer no longer uses this light during rendering.
             * 
             * @param light The light source to be removed.
             */
            void removeLight(DirectionalLight& light);


            /**
             * @brief Clears the list of lights of a specified type in the scene.
             * 
             * This templated method removes all light sources of the specified
             * type from the scene's light list,
             * effectively resetting the collection of that particular light type.
             * 
             * @tparam T The type of light to clear (e.g., PointLight, DirectionalLight).
             */
            template<typename T>
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
             * @brief Removes a drawable entity from the scene.
             * 
             * @param entity The entity to be removed.
             */
            void removeDrawable(const Entity& entity);

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
             * @brief Retrieves the list of lights of a specified type in the scene.
             * 
             * This templated method returns a constant reference to the vector containing 
             * all light sources of the specified type in the scene. It can be used for 
             * querying the lights without modifying the list.
             * 
             * @tparam T The type of light to retrieve (e.g., PointLight, DirectionalLight).
             * @return A constant reference to the vector containing pointers to all light sources of type T.
             */
            template<typename T>
            const std::vector<T*>& getLightList() const;

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
