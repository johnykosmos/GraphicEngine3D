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
        Texture* texture;
    };


} // namespace eng
