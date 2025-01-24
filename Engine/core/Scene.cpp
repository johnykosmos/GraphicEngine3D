#include "Scene.hpp"
#include <X11/X.h>

namespace eng {
    void Scene::addLight(Light* light) {
        lightList.push_back(light);
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
