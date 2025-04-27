#pragma once 

#include "Mesh.hpp"
#include "TransformableObject.hpp"

namespace eng {
    
    
    /**
     * @class Entity
     * @brief Abstract class representing a entity.
     *
     * This class serves as a base class for all entity objects in the application.
     */
    class Entity : public TransformableObject {
        public:
            virtual ~Entity() {}
            /**
             * @brief Retrieves the mesh transformation matrix of the entity.
             * @return Mesh& A reference to the mesh of the entity.
             */
            virtual const Mesh& getMesh() const = 0;
    };



} // namespace eng
