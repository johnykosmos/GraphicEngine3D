#include "Renderer.hpp"

#include "glad/glad.h"

namespace eng {
    void Renderer::draw(const VertexArray& vao, const Shader& shader){
        shader.bind(); 
        shader.setUniform4fv("projection", camera->getViewProjection());
        vao.bind();
        glDrawElements(GL_TRIANGLES, vao.getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);
        vao.unbind();
    }

}
