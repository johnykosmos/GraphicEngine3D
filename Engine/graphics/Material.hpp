#pragma once

#include "Shader.hpp"
#include "Texture.hpp"


namespace eng {
    
    /**
     * @struct Material
     * @brief This struct holds all the material data needed for rendering
     */
    struct Material {
        Shader* shader;
        Texture* texture = nullptr;

        const Vec3 albedo;
        const Vec3 ambient;
        const Vec3 diffuse;
        const Vec3 specular;

        const float shininess;
    };


} // namespace eng
