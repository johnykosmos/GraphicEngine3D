#pragma once

#include "Typedefs.hpp"

namespace eng {

    /**
     * @struct Light
     *
     * @brief Represents the light.
     */
    struct Light {
        const Vec3 color;
        const Vec3 position;

        const float constant;
        const float linear;
        const float quadratic;
    };

}
