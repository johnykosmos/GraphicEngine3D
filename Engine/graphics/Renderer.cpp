#include "glad/glad.h"
#include <GL/gl.h>
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
    } 

    void Renderer::bindMaterial(const Material& material, 
            const Scene& scene) {
        material.shader->bind();
        material.shader->setUniformMat4("projection", 
                scene.getActiveCamera()->getViewProjection());


        auto light = scene.getLightList()[0];
        material.shader->setUniformVec3("lightPos", light.position);
        material.shader->setUniformVec3("lightColor", light.color);
        material.shader->setUniformVec3("cameraPos",
                scene.getActiveCamera()->getPosition());
        material.shader->setUniformVec3("objectColor", material.albedo);
        material.shader->setUniform1f("shininess", material.shininess);

        material.shader->setUniform1i("tex", 0);
        if (material.texture) {
            material.shader->setUniform1i("isTexture", 1);
            material.texture->bind();
        } else {
            material.shader->setUniform1i("isTexture", 0);
            material.texture->unbind();
        }
    }

    void Renderer::clear() const {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::clearToColor(const Vec3& color) const {
         glClearColor(color.x,color.y, color.z, 1.0f);
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

    void Renderer::render(const Scene& scene) {
        for (auto& call : drawCallList) {
            instanceBuffer.updateData(call.transforms.data(), 
                    call.transforms.size() * sizeof(Mat4));
            call.va->configureAttributes(instanceBuffer, instanceLayout, true);
            drawInstanced(*call.va, *call.material, scene, call.transforms.size());
        }
        drawCallList.clear();
    }

    void Renderer::drawIndexed(const VertexArray& vao, const Material& material){
        //bindMaterial(material);
        vao.bind();
        glDrawElements(GL_TRIANGLES, vao.getIndexBuffer()->getCount(), GL_UNSIGNED_INT, 0);
        vao.unbind();
    }

    void Renderer::drawInstanced(const VertexArray& vao, 
            const Material& material, const Scene& scene,
            unsigned int instancesCount){
        bindMaterial(material, scene);
        vao.bind();
        glDrawElementsInstanced(GL_TRIANGLES, vao.getIndexBuffer()->getCount(), GL_UNSIGNED_INT, 0, instancesCount);
        vao.unbind();
    }
}
