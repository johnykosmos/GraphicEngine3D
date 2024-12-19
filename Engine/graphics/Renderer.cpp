#include "glad/glad.h"
#include <GL/gl.h>
#include "Renderer.hpp"



namespace eng {
    
    Renderer::Renderer(const Camera* camera) : camera(camera) {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
    }; 

    void Renderer::draw(const VertexArray& vao, const Shader& shader){
        shader.bind(); 
        shader.setUniform4fv("projection", camera->getViewProjection());
        vao.bind();
        glDrawElements(GL_TRIANGLES, vao.getIndexBuffer()->getCount(), GL_UNSIGNED_INT, 0);
        vao.unbind();
    }

    void Renderer::drawInstanced(const VertexArray& vao, const Shader& shader, const Texture& texture, unsigned int instancesCount){
        shader.bind(); 
        shader.setUniform4fv("projection", camera->getViewProjection());
        shader.setUniform1i("tex", 0);
        texture.bind();
        vao.bind();
        glDrawElementsInstanced(GL_TRIANGLES, vao.getIndexBuffer()->getCount(), GL_UNSIGNED_INT, 0, instancesCount);
        vao.unbind();
    }

}
