#pragma once

#include "GLBuffers.hpp"
#include "Material.hpp"
#include "Scene.hpp"
#include "Entity.hpp"
#include "Typedefs.hpp"
#include "VertexArray.hpp"
#include <vector>


namespace eng {

        /**
         * @struct DrawCall
         * @brief Represents a single rendering call with associated vertex data, material, and transformations.
         */
        struct DrawCall {
            const VertexArray* va;              /**< Pointer to the vertex array used in the draw call. */
            const Material* material;           /**< Pointer to the material used in the draw call. */
            std::vector<Mat4> transforms;       /**< Transformations applied to the objects in the draw call. */

            /**
             * @brief Compares this DrawCall with another for equality.
             * @param otherCall The other DrawCall to compare with.
             * @return True if the DrawCalls are equal, false otherwise.
             */
            bool operator==(const DrawCall& otherCall);
        };


    /**
     * @class Renderer
     * @brief Handles rendering of objects in the scene, 
     * managing draw calls and instanced rendering.
     * 
     * The `Renderer` class provides functionality for batching, 
     * instanced rendering, and managing materials, lights 
     * and camera data for efficient rendering of scenes.
     */
    class Renderer {
        private:
            static std::vector<DrawCall> drawCallList;   /**< List of draw calls to be rendered in the scene. */
            VertexBuffer instanceBuffer;                 /**< Vertex buffer used for instanced rendering data. */
            VertexBufferLayout instanceLayout;           /**< Layout description for the instanced data. */
            UniformBuffer cameraUBO;                     /**< Uniform buffer for storing camera data. */
            UniformBuffer lightUBO;                      /**< Uniform buffer for storing light data. */
            static bool isLightingEnabled;               /**< Boolean flag to control lighting in the scene. */

        private:
            /**
             * @brief Binds a material for rendering.
             * 
             * This method prepares the given material for use in rendering by binding it
             * to the appropriate OpenGL pipeline stages.
             * 
             * @param material The material to bind.
             */
            void bindMaterial(const Material& material);

            /**
             * @brief Uploads camera data to the UBO.
             * 
             * This method uploads the camera's projection matrix and position to the 
             * `cameraUBO` for use in shaders.
             * 
             * @param projection The projection matrix of the camera.
             * @param position The position of the camera in world space.
             */
            void uploadCameraUBO(const Mat4& projection, const Vec3& position);

            /**
             * @brief Uploads light data to the UBO.
             * 
             * This method updates the `lightUBO` with data for point lights and directional lights.
             * 
             * @param pointLights A vector of pointers to point lights in the scene.
             * @param dirLights A vector of pointers to directional lights in the scene.
             */
            void uploadLightUBO(
                const std::vector<PointLight*>& pointLights,
                const std::vector<DirectionalLight*>& dirLights);

            /**
             * @brief Batches multiple draw calls for efficiency.
             * 
             * This method groups multiple draw calls into a single batch for improved
             * rendering performance.
             * 
             * @param va The vertex array associated with the draw calls.
             * @param material The material to use for the draw calls.
             * @param transform The transformation matrix to apply to the batch.
             */
            void batchCalls(const VertexArray& va, const Material& material, const Mat4& transform);

            /**
             * @brief Performs instanced rendering.
             * 
             * This method renders multiple instances of geometry in a single draw call
             * to reduce overhead.
             * 
             * @param vao The vertex array to use for rendering instances.
             * @param instancesCount The number of instances to render.
             */
            void drawInstanced(const VertexArray& vao, unsigned int instancesCount);

            /**
             * @brief Draws indexed geometry using a specified material.
             * 
             * This method renders indexed geometry by binding the appropriate vertex
             * array and issuing a draw command.
             * 
             * @param va The vertex array containing indexed geometry.
             */
            void drawIndexed(const VertexArray& va);

        public:
            /**
             * @brief Default constructor for the Renderer.
             * 
             * Initializes the Renderer and its associated resources.
             */
            Renderer();

            /**
             * @brief Clears the frame.
             * 
             * This method clears the color, depth, and stencil buffers to prepare for a new frame.
             */
            void clear() const;

            /**
             * @brief Clears the frame to the given color.
             * 
             * This method clears the frame with the specified color, setting it as the
             * background for the new frame.
             * 
             * @param color The color to set (RGB).
             */
            void clearToColor(const Vec3& color) const;

            /**
             * @brief Draws an entity using the specified material.
             * 
             * This method renders a given entity using the provided material, applying
             * all necessary transformations and settings.
             * 
             * @param entity The entity to render.
             * @param material The material to use for rendering the entity.
             */
            void drawEntity(const Entity& entity, const Material& material);

            /**
             * @brief Executes all the queued draw calls.
             * 
             * This method processes and executes all batched draw calls for the given
             * scene, rendering it to the screen.
             * 
             * @param scene The scene to render.
             */
            void render(const Scene& scene);

            /**
             * @brief Enables or disables lighting in the scene.
             * 
             * This method allows you to toggle the lighting system on or off.
             * Lighting calculations will be performed when enabled.
             * 
             * @param value A boolean flag to enable (`true`) or disable (`false`) lighting.
             */
            void enableLighting(bool value);
    };
} // namespace eng

