#include "GLBuffers.hpp"
#include <glad/glad.h>

namespace eng{
    VertexBuffer::VertexBuffer(const void* data, unsigned int size){
        glad_glGenBuffers(1, &id); 
        bind();
        glad_glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    void VertexBuffer::bind() const{
        glad_glBindBuffer(GL_ARRAY_BUFFER, id);
    }
    
    void VertexBuffer::unbind() const{
        glad_glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    VertexBuffer::~VertexBuffer(){
        glad_glDeleteBuffers(1, &id);
    }

    IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count){
        glad_glGenBuffers(1, &id); 
        bind();
        glad_glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLuint), data, GL_STATIC_DRAW);
        this->count = count;
    }

    void IndexBuffer::bind() const{
        glad_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    }

    void IndexBuffer::unbind() const{
        glad_glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    IndexBuffer::~IndexBuffer(){
        glad_glDeleteBuffers(1, &id);
    }

    unsigned int IndexBuffer::getCount() const{
        return count;
    }
}
