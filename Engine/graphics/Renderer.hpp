#pragma once

#include "Camera.hpp"
#include "Material.hpp"
#include "Shape.hpp"
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
         * @brief Handles rendering of shapes and objects in the scene, managing draw calls and instanced rendering.
         */
        class Renderer {
        private:
            const Camera* camera;                        /**< Pointer to the active camera used for rendering. */
            static std::vector<DrawCall> drawCallList;   /**< List of draw calls to be rendered in the scene. */
            VertexBuffer instanceBuffer;                 /**< Vertex buffer used for instanced rendering data. */
            VertexBufferLayout instanceLayout;           /**< Layout description for the instanced data. */

            /**
             * @brief Binds a material for rendering.
             * @param material The material to bind.
             */
            void bindMaterial(const Material& material);

            /**
             * @brief Batches multiple draw calls for efficiency.
             * @param va The vertex array associated with the draw calls.
             * @param material The material to use for the draw calls.
             * @param transform The transformation matrix to apply to the batch.
             */
            void batchCalls(const VertexArray& va, const Material& material, const Mat4& transform);

            /**
             * @brief Performs instanced rendering.
             * @param vao The vertex array to use for rendering instances.
             * @param material The material to apply to the instances.
             * @param instancesCount The number of instances to render.
             */
            void drawInstanced(const VertexArray& vao, const Material& material, unsigned int instancesCount);

            /**
             * @brief Draws indexed geometry using a specified material.
             * @param va The vertex array containing indexed geometry.
             * @param material The material to apply to the geometry.
             */
            void drawIndexed(const VertexArray& va, const Material& material);

        public:
            /**
             * @brief Default constructor for the Renderer.
             */
            Renderer();

            /**
             * @brief Sets the active camera for rendering.
             * @param camera The camera to set as active.
             */
            void setCamera(const Camera& camera);

            /**
             * @brief Draws a shape using the specified material.
             * @param shape The shape to render.
             * @param material The material to use for rendering the shape.
             */
            void drawShape(const Shape& shape, const Material& material);

            /**
             * @brief Executes all the queued draw calls.
             */
            void render();
        };

} // namespace eng

