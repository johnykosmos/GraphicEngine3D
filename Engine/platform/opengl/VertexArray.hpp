#pragma once


#include "GLBuffers.hpp"
#include "VertexLayout.hpp"

namespace eng{
    /**
     * @class VertexArray
     *
     * @brief Represents an OpenGL VertexArray
     *
     * This class provides an abstraction for managing OpenGL Vertex Array Objects (VAOs).
     * A VAO stores the state of vertex attributes and the associated vertex buffer 
     * bindings, allowing efficient configuration and rendering of vertex data.     
     */
    class VertexArray{
        private:
            unsigned int id;
            const VertexBuffer* vb;
            const IndexBuffer* ib;
            const VertexBufferLayout* layout;

        public:
        /**
         * @brief Constructs a new, empty Vertex Array Object.
         *
         * Initializes the VAO by generating a unique identifier.
         */
        VertexArray();

        /**
         * @brief Constructs a Vertex Array Object with the given Vertex Buffer, Layout, and Index Buffer.
         *
         * @param vb The Vertex Buffer to associate with the VAO.
         * @param layout The Vertex Buffer Layout describing the structure of the vertex data.
         * @param ib The Index Buffer to associate with the VAO.
         */
        VertexArray(const VertexBuffer& vb, const VertexBufferLayout& layout, const IndexBuffer& ib);

        /**
         * @brief Destroys the Vertex Array Object, releasing its resources.
         */
        ~VertexArray();

        /**
         * @brief Adds a Vertex Buffer and its associated Layout to the VAO.
         *
         * @param vb The Vertex Buffer to add.
         * @param layout The Vertex Buffer Layout describing the structure of the vertex data.
         */
        void addVertexBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);

        /**
         * @brief Adds an Index Buffer to the VAO.
         *
         * @param ib The Index Buffer to add.
         */
        void addIndexBuffer(const IndexBuffer& ib);

        /**
         * @brief Binds the Vertex Array Object, making it the active VAO.
         */
        void bind();

        /**
         * @brief Unbinds the Vertex Array Object, making no VAO active.
         */
        void unbind();

    };


}
