#include "VertexLayout.hpp"

#include "glad/glad.h"

namespace eng{
    template<>
    void VertexBufferLayout::push<float>(unsigned int count){
        layoutElements.push_back({GL_FLOAT, count, GL_FALSE, 4});
        stride += count * sizeof(float);
    }

    const std::vector<VertexBufferElement>& VertexBufferLayout::getElements() const{
        return layoutElements;
    }

    unsigned int VertexBufferLayout::getStride() const{
        return stride;
    }

}
