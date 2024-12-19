#include "glad/glad.h"
#include <GL/gl.h>
#include "Renderer.hpp"



namespace eng {
    
    Renderer::Renderer(const Camera* camera) : camera(camera) {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);
    }; 

    void Renderer::bindMaterial(const Material& material){
        material.shader->bind();
        material.shader->setUniform4fv("projection", camera->getViewProjection());
        material.shader->setUniform1i("tex", 0);
        material.texture->bind();

    }

    void Renderer::drawIndexed(const VertexArray& vao, const Material& material){
        bindMaterial(material);
        vao.bind();
        glDrawElements(GL_TRIANGLES, vao.getIndexBuffer()->getCount(), GL_UNSIGNED_INT, 0);
        vao.unbind();
    }

    void Renderer::drawInstanced(const VertexArray& vao, const Material& material, unsigned int instancesCount){
        bindMaterial(material);
        vao.bind();
        glDrawElementsInstanced(GL_TRIANGLES, vao.getIndexBuffer()->getCount(), GL_UNSIGNED_INT, 0, instancesCount);
        vao.unbind();
    }

}
