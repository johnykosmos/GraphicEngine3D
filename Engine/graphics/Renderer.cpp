#include "Light.hpp"
#include "Typedefs.hpp"
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

        auto& pointLights = scene.getLightList<PointLight>();
        if (!pointLights.empty()) {
            material.shader->setUniform1i("enablePointLights", 1);
            material.shader->setUniform1i("numberOfPointLights", pointLights.size());
            for (int i = 0; i < pointLights.size(); i++) {
                material.shader->setUniformVec3(("pointLights[" + std::to_string(i) + 
                        "].position").c_str(), pointLights[i]->position);
                material.shader->setUniformVec3(("pointLights[" + std::to_string(i) + 
                        "].color").c_str(), pointLights[i]->color);
                material.shader->setUniform1f(("pointLights[" + std::to_string(i) + 
                                    "].constant").c_str(), pointLights[i]->constant);
                material.shader->setUniform1f(("pointLights[" + std::to_string(i) + 
                                    "].linear").c_str(), pointLights[i]->linear);
                material.shader->setUniform1f(("pointLights[" + std::to_string(i) + 
                        "].quadratic").c_str(), pointLights[i]->quadratic);
            }
        } else {
            material.shader->setUniform1i("enablePointLights", 0);
        }

        auto& directionalLights = scene.getLightList<DirectionalLight>();
        if (!directionalLights.empty()) {
            material.shader->setUniform1i("enableDirectionalLights", 1);
            material.shader->setUniform1i("numberOfDirectionalLights", directionalLights.size());
            for (int i = 0; i < directionalLights.size(); i++) {
                material.shader->setUniformVec3(("directionalLights[" + std::to_string(i) + 
                        "].direction").c_str(), directionalLights[i]->direction);
                material.shader->setUniformVec3(("directionalLights[" + std::to_string(i) + 
                        "].color").c_str(), directionalLights[i]->color);
            }
        } else {
            material.shader->setUniform1i("enableDirectionalLights", 0);
        }
        
        material.shader->setUniformVec3("cameraPos", scene.getActiveCamera()->getPosition());

        material.shader->setUniformVec3("material.albedo", material.albedo);
        material.shader->setUniformVec3("material.ambient", material.ambient);
        material.shader->setUniformVec3("material.diffuse", material.diffuse);
        material.shader->setUniformVec3("material.specular", material.specular);
        material.shader->setUniform1f("material.shininess", material.shininess);

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

    void Renderer::drawEntity(const Entity& entity, const Material& material) {
        batchCalls(entity.getMesh().getVertexArray(),
                material, entity.getTransform());        
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
        for (auto& drawable : scene.getDrawables()) {
            drawEntity(*drawable.entity, *drawable.material);
        }

        for (auto& call : drawCallList) {
            instanceBuffer.updateData(call.transforms.data(), 
                    call.transforms.size() * sizeof(Mat4));
            call.va->configureAttributes(instanceBuffer, instanceLayout, true);
            bindMaterial(*call.material, scene);
            drawInstanced(*call.va, call.transforms.size());
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
            unsigned int instancesCount){
        vao.bind();
        glDrawElementsInstanced(GL_TRIANGLES, vao.getIndexBuffer()->getCount(), GL_UNSIGNED_INT, 0, instancesCount);
        vao.unbind();
    }
}
