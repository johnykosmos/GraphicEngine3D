#pragma once

#include <vector>
namespace eng{
    /**
     * @struct VertexBufferElement
     * 
     * @brief Represents a single attribute in a Vertex Buffer.
     * 
     * Each element describes the data type, count, and normalization 
     * status of a vertex attribute.
     */
    struct VertexBufferElement {
        unsigned int type;       
        unsigned int count;      
        unsigned int normalized;
        unsigned int size;
    };

    /**
     * @class VertexBufferLayout
     * 
     * @brief Manages the layout of attributes within a Vertex Buffer.
     * 
     * This class stores information about vertex attributes and calculates 
     * the total stride (the size in bytes of a single vertex).
     */
    class VertexBufferLayout {
    private:
        std::vector<VertexBufferElement> layoutElements; 
        unsigned int stride;                            

    public:
        /**
         * @brief Constructs a VertexBufferLayout with an initial stride of 0.
         */
        VertexBufferLayout() : stride(0) {}

        /**
         * @brief Adds an attribute to the layout.
         * 
         * @tparam T The data type of the attribute (e.g., float, int).
         * @param count The number of components in the attribute (e.g., 3 for vec3).
         */
        template<typename T>
        void push(unsigned int count);

        /**
         * @brief Retrieves the list of attributes in the buffer layout.
         * 
         * @return A constant reference to a vector of VertexBufferElement.
         */
        const std::vector<VertexBufferElement>& getElements() const;

        /**
         * @brief Gets the total stride of the layout in bytes.
         * 
         * @return The stride of the layout.
         */
        unsigned int getStride() const;
    };

}
