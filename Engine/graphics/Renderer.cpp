#include "Renderer.hpp"

#include "glad/glad.h"

namespace eng {
    
    Renderer::Renderer(const Camera* camera) : camera(camera) {
        glEnable(GL_DEPTH_TEST);
    }; 

    void Renderer::draw(const VertexArray& vao, const Shader& shader){
        shader.bind(); 
        shader.setUniform4fv("projection", camera->getViewProjection());
        vao.bind();
        glDrawElements(GL_TRIANGLES, vao.getIndexBuffer()->getCount(), GL_UNSIGNED_INT, 0);
        vao.unbind();
    }

    void Renderer::drawInstanced(const VertexArray& vao, const Shader& shader, unsigned int instancesCount){
        shader.bind(); 
        shader.setUniform4fv("projection", camera->getViewProjection());
        vao.bind();
        glDrawElementsInstanced(GL_TRIANGLES, vao.getIndexBuffer()->getCount(), GL_UNSIGNED_INT, 0, instancesCount);
        vao.unbind();
    }

}
