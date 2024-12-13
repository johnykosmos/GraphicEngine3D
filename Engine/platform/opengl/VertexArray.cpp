#include "VertexArray.hpp"
#include "GLBuffers.hpp"
#include "VertexLayout.hpp"
#include "glad/glad.h"
#include <cstdint>

namespace  eng{
    VertexArray::VertexArray(){
        glGenVertexArrays(1, &id);
    }

    VertexArray::VertexArray(const VertexBuffer& vb, 
            const VertexBufferLayout& layout, 
            const IndexBuffer& ib
            ) : VertexArray(){
        addVertexBuffer(vb, layout);
        addIndexBuffer(ib);
    }

    void VertexArray::addVertexBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout){
        bind();
        vb.bind();

        GLuint offset = 0;
        auto elements = layout.getElements();
        for (auto element : elements){
            glVertexAttribPointer(attributesCount, 
                    element.count, 
                    element.type,
                    element.normalized, 
                    layout.getStride(), 
                    (void*)(uintptr_t)offset
                ); 
            glEnableVertexAttribArray(attributesCount);
            offset += element.count * element.size;
            attributesCount++;
        }
    }
    
    void VertexArray::addIndexBuffer(const IndexBuffer& ib) {
        this->ib = &ib;
        bind();
        ib.bind();
    }

    void VertexArray::bind() const{
        glBindVertexArray(id);
    }

    void VertexArray::unbind() const{
        glBindVertexArray(0);
    }

    const IndexBuffer* VertexArray::getIndexBuffer() const{
        return ib;
    }

    VertexArray::~VertexArray(){
        glDeleteVertexArrays(1, &id);
    }
}
