#pragma once

#include "Shader.hpp"


namespace eng {
    
    /**
     * @struct Material
     * @brief This struct holds all the material data needed for rendering
     */
    struct Material {
        Shader* shader;

        void bind();
    };


} // namespace eng
