#pragma once 

#include "Mesh.hpp"
#include "TransformableObject.hpp"

namespace eng {
    
    
    /**
     * @class Shape
     * @brief Abstract class representing a shape.
     *
     * This class serves as a base class for all shape objects in the application.
     */
    class Shape : public TransformableObject {
        public:
            virtual ~Shape() {}
            /**
             * @brief Retrieves the mesh transformation matrix of the shape.
             * @return Mesh& A reference to the mesh of the shape.
             */
            virtual Mesh& getMesh() const = 0;
    };



} // namespace eng
