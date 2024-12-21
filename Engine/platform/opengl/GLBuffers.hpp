#pragma once

#include "Typedefs.hpp"

namespace eng{

    /**
     * @struct Vertex
     * @brief Represents a vertex
     */
    struct Vertex {
        Vec3 vertices;
        Vec3 color;
        Vec2 texturePos;
    };

    /**
     * @class VertexBuffer
     *  
     * @brief Represents an OpenGL Vertex Buffer
     *
     * This class provides an abstraction for managing OpenGL VBOs,
     * which store vertex data such as positions, normals, colors, 
     * and texture coordinates.
     */
    class VertexBuffer{
        private:
            unsigned int id;

        public:
            /**
             * @brief Constructs a VertexBuffer and generates an OpenGL buffer ID 
             */
            VertexBuffer();

            /**
             * @brief Constructs a VertexBuffer, generates an OpenGL buffer ID and
             * uploads data to the buffer
             *
             * @param data Void pointer to the data to be uploaded
             * @param size Size of the data in bytes
             */
            VertexBuffer(const void* data, unsigned int size);

            /**
             * @brief Destroys the VertexBuffer and deletes the OpenGL buffer.
             */
            ~VertexBuffer();

            /**
             * @brief binds the vertex buffer
             */
            void bind() const;

            /**
             * @brief Unbinds the vertex buffer
             */
            void unbind() const;

            /**
             * @brief Updates the buffer data 
             *
             * @param data Void pointer to the data to be uploaded
             * @param size Size of the data in bytes
             */
            void updateData(const void* data, unsigned int size);
    };

    /**
     * @class IndexBuffer
     *
     * @brief Represents an OpenGL IndexBuffer
     *
     * This class provides an abstraction for managing OpenGL IBOs,
     * which store indices that define the order in which vertices are rendered.
     */
    class IndexBuffer{
        private:
            unsigned int id;
            unsigned int count;

        public:
            /**
             * @brief Constructs a IndexBuffer and generates an OpenGL buffer ID 
             *
             * @param data Unsigned int pointer to the indices data
             * @param count Count of the indices 
             */
            IndexBuffer(const unsigned int* data, unsigned int count);

             /**
             * @brief Destroys the IndexBuffer and deletes the OpenGL buffer.
             */
            ~IndexBuffer();

            /**
             * @brief Binds the index buffer
             */
            void bind() const;

            /**
             * @brief Unbinds the index buffer
             */
            void unbind() const;
            
            unsigned int getCount() const;
    };
}
