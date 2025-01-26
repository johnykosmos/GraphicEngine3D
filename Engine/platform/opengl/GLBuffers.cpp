#include "GLBuffers.hpp"
#include <glad/glad.h>

namespace eng{
    VertexBuffer::VertexBuffer() {
        glGenBuffers(1, &id);
    }

    VertexBuffer::VertexBuffer(const void* data, unsigned int size){
        glGenBuffers(1, &id); 
        updateData(data, size);
    }

    void VertexBuffer::bind() const{
        glBindBuffer(GL_ARRAY_BUFFER, id);
    }
    
    void VertexBuffer::unbind() const{
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void VertexBuffer::updateData(const void* data, unsigned int size) {
        bind();
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }

    VertexBuffer::~VertexBuffer(){
        glDeleteBuffers(1, &id);
    }

    IndexBuffer::IndexBuffer() {
        glGenBuffers(1, &id);
    }

    IndexBuffer::IndexBuffer(const unsigned int* data, unsigned int count){
        glGenBuffers(1, &id); 
        updateData(data, count);
    }

    void IndexBuffer::updateData(const void* data, unsigned int count) {
        bind();
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW);
        this->count = count;
    }

    void IndexBuffer::bind() const{
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, id);
    }

    void IndexBuffer::unbind() const{
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

    IndexBuffer::~IndexBuffer(){
        glDeleteBuffers(1, &id);
    }

    unsigned int IndexBuffer::getCount() const{
        return count;
    }
    
    UniformBuffer::UniformBuffer() {
        glGenBuffers(1, &id);
    }

    UniformBuffer::UniformBuffer(const void* data, 
            unsigned int size) : UniformBuffer() {
        updateData(data, size); 
    }

    void UniformBuffer::bindToPoint(unsigned int bindingPoint) const {
        glBindBufferBase(GL_UNIFORM_BUFFER, bindingPoint, id);
    }

    void UniformBuffer::bind() const {
        glBindBuffer(GL_UNIFORM_BUFFER, id);
    }

    void UniformBuffer::unbind() const{
        glBindBuffer(GL_UNIFORM_BUFFER, 0);
    }

    void UniformBuffer::updateData(const void* data, unsigned int size) {
        bind();
        glBufferData(GL_UNIFORM_BUFFER, size, nullptr, GL_STATIC_DRAW);
        glBufferSubData(GL_UNIFORM_BUFFER, 0, size, data); 
    }

    UniformBuffer::~UniformBuffer(){
        glDeleteBuffers(1, &id);
    }


}
