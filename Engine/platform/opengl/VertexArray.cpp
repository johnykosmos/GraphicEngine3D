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
        configureAttributes(vb, layout, false);
        addIndexBuffer(ib);
    }
    
    void VertexArray::configureAttributes(const VertexBuffer& vb, const VertexBufferLayout& layout, bool isInstanced) const {
        bind();
        vb.bind();

        GLuint offset = 0;
        unsigned int index = (!isInstanced) ? 0 : 3;
        auto elements = layout.getElements();
        for (const auto& element : elements) {
            glVertexAttribPointer(index,
                                  element.count,
                                  element.type,
                                  element.normalized,
                                  layout.getStride(),
                                  (void*)(uintptr_t)offset);
            glEnableVertexAttribArray(index);

            if (isInstanced) {
                glVertexAttribDivisor(index, 1);
            }

            offset += element.count * element.size;
            index++;
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
