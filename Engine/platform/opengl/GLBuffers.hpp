#pragma once

#include "Typedefs.hpp"

namespace eng{

    /**
     * @struct Vertex
     * @brief Represents a vertex
     */
    struct Vertex {
        Vec3 vertices;
        Vec3 normal;
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
             * @brief Constructs an IndexBuffer and generates an OpenGL buffer ID 
             */
            IndexBuffer();

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

            /**
             * @brief Updates the buffer data 
             *
             * @param data Void pointer to the data to be uploaded
             * @param size Size of the data in bytes
             */
            void updateData(const void* data, unsigned int count);
            
            /**
             * @brief Gets the index buffer count.
             *
             * @return unsigned int Count of indices.
             */
            unsigned int getCount() const;
    };

    
    /**
     * @class UniformBuffer
     * @brief Represents a Uniform Buffer Object (UBO) in OpenGL.
     * 
     * This class provides an abstraction for managing uniform buffers in OpenGL. 
     * It allows you to create, bind, update, and manage uniform buffer objects, 
     * which are used to share data between the CPU and shaders.
     */
    class UniformBuffer {
        private:
            unsigned int id; ///< The OpenGL buffer ID for the uniform buffer.

        public:
            /**
             * @brief Constructs a UniformBuffer and generates an OpenGL buffer ID.
             * 
             * This constructor initializes the UniformBuffer object and generates
             * an OpenGL buffer ID for use with UBOs.
             */
            UniformBuffer();

            /**
             * @brief Constructs a UniformBuffer and generates an OpenGL buffer ID with initial data.
             * 
             * This constructor initializes the UniformBuffer object, generates an OpenGL
             * buffer ID, and uploads the provided data to the buffer.
             * 
             * @param data Pointer to the uniform data to be uploaded.
             * @param size Size of the data in bytes.
             */
            UniformBuffer(const void* data, unsigned int size);

            /**
             * @brief Destroys the UniformBuffer and deletes the OpenGL buffer.
             * 
             * This destructor cleans up the UniformBuffer object by deleting the
             * associated OpenGL buffer to free GPU resources.
             */
            ~UniformBuffer();

            /**
             * @brief Binds the uniform buffer to a specific binding point in the shader.
             * 
             * This method binds the uniform buffer object to a given binding point, allowing
             * shaders to access the data stored in the buffer at the specified binding point.
             * 
             * @param bindingPoint The binding point to which the buffer should be bound.
             */
            void bindToPoint(unsigned int bindingPoint) const;

            /**
             * @brief Binds the uniform buffer.
             * 
             * This method binds the uniform buffer object to make it the active buffer
             * for subsequent OpenGL operations.
             */
            void bind() const;

            /**
             * @brief Unbinds the uniform buffer.
             * 
             * This method unbinds the currently bound uniform buffer object, ensuring that
             * no buffer is active for subsequent OpenGL operations.
             */
            void unbind() const;

            /**
             * @brief Updates the buffer data.
             * 
             * This method updates the contents of the uniform buffer by uploading new
             * data to the buffer. It replaces the existing data with the provided data.
             * 
             * @param data Pointer to the data to be uploaded.
             * @param size Size of the data in bytes.
             */
            void updateData(const void* data, unsigned int size);
    };
} // namespace eng
