#pragma once


#include "GLBuffers.hpp"
#include "VertexArray.hpp"
#include "VertexLayout.hpp"


namespace eng {
    
    /**
     * @class Mesh
     * @brief Represents a 3D mesh consisting of vertex and index data.
     * 
     * This class encapsulates the vertex buffer, index buffer, vertex array, 
     * and layout, making it easier to manage and render 3D meshes in OpenGL.
     */
    class Mesh {
        private:
            /**
             * @brief The vertex buffer that holds the mesh's vertex data.
             */
            VertexBuffer vb;

            /**
             * @brief The index buffer that holds the mesh's index data.
             */
            IndexBuffer ib;

            /**
             * @brief Describes the layout of the vertex data (e.g., position, normal, etc.).
             */
            VertexBufferLayout layout;

            /**
             * @brief The vertex array object (VAO) that binds the vertex and index buffers.
             */
            VertexArray va;

        public:
            
            /**
             * @brief Constructs an uninitialized mesh.
             */
            Mesh();

            /**
             * @brief Constructs a Mesh with the provided vertex and index data.
             * 
             * This constructor creates the necessary buffers for storing the vertex
             * and index data, and initializes the vertex array object (VAO).
             * 
             * @param vertices Array of vertices that represent the mesh.
             * @param vertexCount The number of vertices in the array.
             * @param indices Array of indices that define how the vertices are connected.
             * @param indexCount The number of indices in the array.
             */
            explicit Mesh(const Vertex vertices[], size_t vertexCount, const unsigned int indices[], size_t indexCount);

            /**
             * @brief Default destructor.
             * 
             * The destructor automatically handles resource cleanup for the buffers
             * and the vertex array when the Mesh object is destroyed.
             */
            ~Mesh() = default;

            /**
             * @brief Returns a reference to the vertex array object (VAO).
             * 
             * This function provides access to the VAO, which is used to bind the
             * mesh's vertex and index buffers for rendering.
             * 
             * @return VertexArray& The reference to the vertex array object.
             */
            const VertexArray& getVertexArray() const;

            /**
             * @brief Updates all the mesh data with the provided vertex and index data.
             *
             * @param vertices Array of vertices that represent the mesh.
             * @param vertexCount The number of vertices in the array.
             * @param indices Array of indices that define how the vertices are connected.
             * @param indexCount The number of indices in the array.
             */
            void updateData(const Vertex vertices[], size_t vertexCount, const unsigned int indices[], size_t indexCount);

    };
} 
