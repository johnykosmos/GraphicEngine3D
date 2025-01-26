#pragma once

#include "Typedefs.hpp"

#define MAX_POINT_LIGHTS 20
#define MAX_DIRECTIONAL_LIGHTS 5

namespace eng::DataUBO {

    
    /**
     * @struct CameraData
     * @brief Represents the camera data used for rendering.
     * 
     * This struct stores information about the camera's projection matrix and position 
     * for use in the rendering pipeline.
     */
    struct CameraData {
        Mat4 projection; ///< The projection matrix of the camera.
        Vec3 position;   ///< The position of the camera in world space.
    };

    /**
     * @struct DirLightData
     * @brief Represents a directional light in the scene.
     * 
     * A directional light simulates light coming from an infinitely distant source,
     * such as sunlight, and has a specific color and direction.
     *
     * @note The data is aligned to meet GPU uniform buffer layout requirements. 
     */
    struct alignas(16) DirLightData {
        Vec3 color;      ///< The color of the light (RGB).
        float padding1;  ///< Padding to align the next member to 16 bytes.
        Vec3 direction;  ///< The direction of the light rays.
        float padding2;  ///< Padding to ensure 16-byte alignment.
    };

    /**
     * @struct PointLightData
     * @brief Represents a point light in the scene.
     * 
     * A point light emits light in all directions from a single position in space.
     * The light's intensity diminishes with distance based on attenuation factors.
     *
     * @note The data is aligned to meet GPU uniform buffer layout requirements.
     */
    struct alignas(16) PointLightData {
        Vec3 color;      ///< The color of the light (RGB).
        float constant;  ///< The constant attenuation factor.
        Vec3 position;   ///< The position of the light in world space.
        float linear;    ///< The linear attenuation factor.
        Vec3 padding1;   ///< Padding to align the next member to 16 bytes.
        float quadratic; ///< The quadratic attenuation factor.
    };

    /**
     * @struct LightData
     * @brief Holds the lighting data for the scene.
     * 
     * This struct contains arrays of point lights and directional lights, along with 
     * the number of lights in each category, for use in the lighting calculations.
     * 
     * @note The data is aligned to meet GPU uniform buffer layout requirements.
     */
    struct alignas(16) LightData {
        int numberOfPointLights; ///< The number of active point lights in the scene.
        int numberOfDirectionalLights; ///< The number of active directional lights in the scene.
        PointLightData pointLights[MAX_POINT_LIGHTS]; ///< Array of point lights.
        DirLightData directionalLights[MAX_DIRECTIONAL_LIGHTS]; ///< Array of directional lights.
    };
} // namespace eng
