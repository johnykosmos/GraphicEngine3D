#include "Light.hpp"
#include "Typedefs.hpp"
#include "glad/glad.h"
#include <GL/gl.h>
#include "Renderer.hpp"
#include "DataUBO.hpp"

namespace eng {
    
    bool DrawCall::operator==(const DrawCall& otherCall) {
        return (va == otherCall.va && material == otherCall.material);
    }

    std::vector<DrawCall> Renderer::drawCallList;

    bool Renderer::isLightingEnabled = true;

    Renderer::Renderer() {
        glEnable(GL_DEPTH_TEST);
        glEnable(GL_CULL_FACE);

        instanceLayout.push<float>(4);
        instanceLayout.push<float>(4);
        instanceLayout.push<float>(4); 
        instanceLayout.push<float>(4);

    } 

    void Renderer::bindMaterial(const Material& material) {
        material.shader->bind();

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

    void Renderer::uploadCameraUBO(const Mat4& projection,
            const Vec3& position) {
        DataUBO::CameraData data = {
            .projection = projection,
            .position = position
        };
        cameraUBO.bindToPoint(0);
        cameraUBO.updateData(&data, sizeof(data));
    }

    void Renderer::uploadLightUBO(const std::vector<PointLight*>& pointLights,
                        const std::vector<DirectionalLight*>& dirLights) {
        DataUBO::LightData data;
        
        if (isLightingEnabled) {

            data.isLightingEnabled = 1;
            data.numberOfPointLights = pointLights.size();
            data.numberOfDirectionalLights = dirLights.size();

            for (int i = 0; i < pointLights.size(); i++) {
                data.pointLights[i] = {
                    .color = pointLights[i]->color,
                    .constant = pointLights[i]->constant,
                    .position = pointLights[i]->position,
                    .linear = pointLights[i]->linear,
                    .quadratic = pointLights[i]->quadratic
                };
            }

            for (int i = 0; i < dirLights.size(); i++) {
                data.directionalLights[i] = {
                    .color = dirLights[i]->color,
                    .direction = dirLights[i]->direction
                };
            }
        } else {
            data.isLightingEnabled = 0;
        }

        lightUBO.bindToPoint(1);
        lightUBO.updateData(&data, sizeof(data));
    }

    void Renderer::clear() const {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    }

    void Renderer::clearToColor(const Vec3& color) const {
         glClearColor(color.x,color.y, color.z, 1.0f);
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

        uploadCameraUBO(
                scene.getActiveCamera()->getViewProjection(), 
                scene.getActiveCamera()->getPosition()
                );
        
          
        uploadLightUBO(
                scene.getLightList<PointLight>(), 
                scene.getLightList<DirectionalLight>()
                );
        

        for (auto& call : drawCallList) {
            instanceBuffer.updateData(call.transforms.data(), 
                    call.transforms.size() * sizeof(Mat4));
            call.va->configureAttributes(instanceBuffer, instanceLayout, true);
            bindMaterial(*call.material);
            drawInstanced(*call.va, call.transforms.size());
        }
        drawCallList.clear();
    }

    void Renderer::drawEntity(const Entity& entity, const Material& material) {
        batchCalls(entity.getMesh().getVertexArray(),
                material, entity.getTransform());        
    }

    void Renderer::drawIndexed(const VertexArray& vao){
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

    void Renderer::enableLighting(bool value) {
        isLightingEnabled = value;
    }

}
