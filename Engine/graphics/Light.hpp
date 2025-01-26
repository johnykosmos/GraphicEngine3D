#pragma once

#include "Typedefs.hpp"

namespace eng {

    /**
     * @struct DirectionalLight
     * 
     * @brief Represents a directional light in a 3D scene.
     * 
     * A directional light emits light in a specific direction, simulating a light 
     * source that is infinitely far away (e.g., sunlight). The light rays are 
     * parallel and do not diminish in intensity with distance.
     */
    struct DirectionalLight {
        Vec3 color; ///< The color of the light (RGB).
        Vec3 direction; ///< The direction in which the light rays travel.
    };

    /**
     * @struct PointLight
     * 
     * @brief Represents a point light in a 3D scene.
     * 
     * A point light emits light in all directions from a single point in space. 
     * Its intensity diminishes with distance based on attenuation factors.
     */
    struct PointLight {
        Vec3 color; ///< The color of the light (RGB).
        Vec3 position; ///< The position of the light in world space.

        float constant;  ///< The constant attenuation factor.
        float linear;    ///< The linear attenuation factor.
        float quadratic; ///< The quadratic attenuation factor.
    };
}
