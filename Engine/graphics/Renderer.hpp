#pragma once

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
         * @brief Handles rendering of objects in the scene, managing draw calls and instanced rendering.
         */
        class Renderer {
        private:
            static std::vector<DrawCall> drawCallList;   /**< List of draw calls to be rendered in the scene. */
            VertexBuffer instanceBuffer;                 /**< Vertex buffer used for instanced rendering data. */
            VertexBufferLayout instanceLayout;           /**< Layout description for the instanced data. */

            /**
             * @brief Binds a material for rendering.
             * @param material The material to bind.
             * @param scene The scene elements to bind.
             */
            void bindMaterial(const Material& material, 
                const Scene& scene);

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
             * @param scene The scene to draw
             * @param instancesCount The number of instances to render.
             */
            void drawInstanced(const VertexArray& vao, const Material& material, const Scene& scene, unsigned int instancesCount);

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
             * @brief Clears the frame.
             */
            void clear() const;

            /**
             * @brief Clears the frame to the given color.
             * @param color The color to set.
             */
            void clearToColor(const Vec3& color) const;

            /**
             * @brief Draws a entity using the specified material.
             * @param entity The entity to render.
             * @param material The material to use for rendering the entity.
             */
            void drawEntity(const Entity& entity, const Material& material);

            /**
             * @brief Executes all the queued draw calls.
             * @param scene The scene to render.
             */
            void render(const Scene& scene);
        };

} // namespace eng

