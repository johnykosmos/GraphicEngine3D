#include "Typedefs.hpp"
#include "glad/glad.h"
#include <GL/gl.h>
#include <iostream>
#include "Renderer.hpp"



namespace eng {
    
    bool DrawCall::operator==(const DrawCall& otherCall) {
        return (va == otherCall.va && material == otherCall.material);
    }

    std::vector<DrawCall> Renderer::drawCallList;

    Renderer::Renderer() {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);

        instanceLayout.push<float>(4);
        instanceLayout.push<float>(4);
        instanceLayout.push<float>(4); 
        instanceLayout.push<float>(4);
    }; 

    void Renderer::setCamera(const Camera& camera) {
        this->camera = &camera;
    }

    void Renderer::bindMaterial(const Material& material) {
        material.shader->bind();
        material.shader->setUniformMat4("projection", 
                camera->getViewProjection());
        material.shader->setUniform1i("tex", 0);
        material.texture->bind();
    }

    void Renderer::drawShape(const Shape& shape, const Material& material) {
        batchCalls(shape.getMesh().getVertexArray(),
                material, shape.getTransform());        
    }

    void Renderer::batchCalls(const VertexArray& va, const Material& material,
                    const Mat4& transform) {
        DrawCall incomingCall = {
            .va = &va,
            .material = &material
        };

        for (auto& call : drawCallList) {
            if (call == incomingCall) {
                call.transforms.push_back(transform);
                return;
            }
        }
        incomingCall.transforms.push_back(transform);
        drawCallList.push_back(incomingCall);
    }

    void Renderer::render() {
        for (auto& call : drawCallList) {
            instanceBuffer.updateData(call.transforms.data(), 
                    call.transforms.size() * sizeof(Mat4));
            call.va->configureAttributes(instanceBuffer, instanceLayout, true);
            drawInstanced(*call.va, *call.material, call.transforms.size());
        }
        drawCallList.clear();
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
