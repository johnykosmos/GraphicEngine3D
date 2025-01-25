#include "Scene.hpp"
#include <algorithm>

namespace eng {
    void Scene::addLight(Light* light) {
        lightList.push_back(light);
    }
    
    void Scene::removeLight(Light* light) {
        auto it = std::find(lightList.begin(), lightList.end(), light);
        if (it != lightList.end()) {
            lightList.erase(it);
        }
    }

    void Scene::clearLightList() {
        lightList.clear();
    }

    const std::vector<Light*>& Scene::getLightList() const {
        return lightList;
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
