#include "VertexArray.hpp"
#include "VertexLayout.hpp"
#include "glad/glad.h"

namespace  eng{
    VertexArray::VertexArray(){
        glad_glGenVertexArrays(1, &id);
    }

    VertexArray::VertexArray(const VertexBuffer& vb, 
            const VertexBufferLayout& layout, 
            const IndexBuffer& ib
            ) : VertexArray(){
        addVertexBuffer(vb, layout);
        addIndexBuffer(ib);
    }

    void VertexArray::addVertexBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout){
        this->vb = &vb;
        this->layout = &layout;
        bind();
        vb.bind();
        int index = 0;
        GLuint offset = 0;
        auto elements = layout.getElements();
        for (auto element : elements){
            glad_glVertexAttribPointer(index, 
                    element.count, 
                    element.type,
                    element.normalized, 
                    layout.getStride(), 
                    (void*)(uintptr_t)offset
                ); 
            glad_glEnableVertexAttribArray(index);
            offset += element.count * element.size;
            index++;
        }
    }
    
    void VertexArray::addIndexBuffer(const IndexBuffer& ib) {
        this->ib = &ib;
        bind();
        ib.bind();
    }

    void VertexArray::bind(){
        glad_glBindVertexArray(id);
    }

    void VertexArray::unbind(){
        glad_glBindVertexArray(0);
    }

    VertexArray::~VertexArray(){
        glad_glDeleteVertexArrays(1, &id);
    }
}
