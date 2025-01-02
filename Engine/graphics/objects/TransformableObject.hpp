#pragma once 

#include "Typedefs.hpp"

namespace eng {
     
    
    /**
     * @class TransformableObject
     * @brief A class representing an object that can be transformed.
     *
     * This class provides functionality for applying
     * transformations such as translation, rotation, and scaling to an object.
     * These transformations are applied to the object's internal transformation matrix (`Mat4`),
     * and the transformations can be chained together for convenience.
     */
    class TransformableObject {
        private:
            Vec3 rotation = {0, 0, 0}; ///< The object's rotation.
            float rotationAngle = 0.0f; ///< The object's rotation angle.
            Vec3 scaling = {0, 0, 0}; ///< The object's  scaling.
            Mat4 transform; ///< The transformation matrix representing the object's position, rotation, and scale.
        
        public:
            /**
             * @brief Default constructor.
             *
             * Initializes the object with an identity transformation matrix, meaning
             * no translation, rotation, or scaling is applied initially.
             */
            TransformableObject();

            /**
             * @brief Retrieves the transformation matrix of the object.
             *
             * This method returns the current transformation matrix of the object.
             * The matrix can be used to render the object after applying transformations.
             *
             * @return const Mat4& A constant reference to the transformation matrix.
             */
            const Mat4& getTransform() const;

            /**
             * @brief Applies a rotation to the object.
             *
             * This method applies a rotation to the object's transformation matrix.
             * The rotation is performed around the specified vector by the given
             * angle in degrees. This method returns the object itself to allow
             * method chaining.
             *
             * @param angle The angle of rotation in degrees.
             * @param vector The axis vector to rotate around (typically `Vec3(0,1,0)` for rotation around Y-axis).
             * @return TransformableObject& A reference to the current object for method chaining.
             */
            TransformableObject& rotate(float angle, const Vec3& vector);

            /**
             * @brief Applies a translation to the object.
             *
             * This method applies a translation (movement) to the object's transformation matrix.
             * The object will be moved by the specified vector in 3D space. This method returns
             * the object itself to allow method chaining.
             *
             * @param vector The translation vector, representing the movement in the X, Y, and Z directions.
             * @return TransformableObject& A reference to the current object for method chaining.
             */
            TransformableObject& translate(const Vec3& vector);

            /**
             * @brief Applies a scaling to the object.
             *
             * This method applies a scaling transformation to the object's transformation matrix.
             * The scaling is applied uniformly or non-uniformly along the X, Y, and Z axes.
             * This method returns the object itself to allow method chaining.
             *
             * @param scaleVector A vector representing the scaling factor along the X, Y, and Z axes.
             * @return TransformableObject& A reference to the current object for method chaining.
             */
            TransformableObject& scale(const Vec3& scaleVector);

            /**
            * @brief Sets the object's position directly.
            *
            * This method replaces the current translation component of the transformation
            * matrix with the provided position. This is useful for directly positioning 
            * the object in 3D space without considering its current transform.
            *
            * @param position The new position to set for the object representing X, Y, and Z coordinates.
            * @return TransformableObject& A reference to the current object for method chaining.
            */
            TransformableObject& setPosition(const Vec3& position);
    };



} // namespace eng
