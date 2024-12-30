#include "Scene.hpp"

namespace eng {
    void Scene::addLight(const Light& light) {
        lightList.push_back(light);
    }
    
    void Scene::clearLightList() {
        lightList.clear();
    }

    const std::vector<Light>& Scene::getLightList() const {
        return lightList;
    }

    void Scene::setActiveCamera(Camera& camera) {
        activeCamera = &camera;
    }

    Camera* Scene::getActiveCamera() const {
        return activeCamera;
    }

} // namespace eng
