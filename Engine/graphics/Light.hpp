#pragma once

#include "Typedefs.hpp"

namespace eng {

    /**
     * @struct Light
     *
     * @brief Represents the light.
     */
    struct Light {
        Vec3 color;
        Vec3 position;

        float constant;
        float linear;
        float quadratic;
    };

}
