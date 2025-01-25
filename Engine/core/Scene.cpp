#include "Scene.hpp"
#include <algorithm>

namespace eng {
    
    void Scene::addLight(PointLight& light) {
        pointLightList.push_back(&light);
    }

    void Scene::addLight(DirectionalLight& light) {
        directionalLightList.push_back(&light);
    }

    void Scene::removeLight(PointLight& light) {
        auto it = std::find(pointLightList.begin(), pointLightList.end(), 
                &light);
        if (it != pointLightList.end()) {
            pointLightList.erase(it);
        }
    }

    void Scene::removeLight(DirectionalLight& light) {
        auto it = std::find(directionalLightList.begin(), 
                directionalLightList.end(), &light);
        if (it != directionalLightList.end()) {
            directionalLightList.erase(it);
        }
    }

    template<>
    void Scene::clearLightList<PointLight>() {
        pointLightList.clear();
    }

    template<>
    void Scene::clearLightList<DirectionalLight>() {
        directionalLightList.clear();
    }

    template<>
    const std::vector<PointLight*>& Scene::getLightList<PointLight>() const {
        return pointLightList;
    }

    template<>
    const std::vector<DirectionalLight*>& Scene::getLightList<DirectionalLight>() const {
        return directionalLightList;
    }

    void Scene::addDrawable(const Entity& entity, const Material& material) {
        drawables.push_back(Drawable{
                .entity = &entity,
                .material = &material
                });
    }
    
    void Scene::removeDrawable(const Entity& entity) {
        auto it = std::remove_if(drawables.begin(), drawables.end(),
                [&entity](const Drawable& drawable) -> bool {
                    return drawable.entity == &entity;
                });
        if (it != drawables.end()) {
            drawables.erase(it);
        }
    }

    void Scene::clearDrawables() {
        drawables.clear();
    }

    const std::vector<Drawable>& Scene::getDrawables() const {
        return drawables;
    }

    void Scene::setActiveCamera(Camera& camera) {
        activeCamera = &camera;
    }

    Camera* Scene::getActiveCamera() const {
        return activeCamera;
    }

} // namespace eng
