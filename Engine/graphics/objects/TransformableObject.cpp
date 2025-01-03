#include "TransformableObject.hpp"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/trigonometric.hpp>

namespace eng {

    TransformableObject::TransformableObject() : transform(Mat4(1.0f)) {}

    const Mat4& TransformableObject::getTransform() const {
        return transform;
    }

    TransformableObject& TransformableObject::rotate(float angle,
            const Vec3& vector) {
        rotation = vector;
        rotationAngle = angle;
        transform = glm::rotate(transform, glm::radians(angle), vector); 
        return *this;
    }

    TransformableObject& TransformableObject::translate(const Vec3& vector) {
        transform = glm::translate(transform, vector);
        return *this;
    }

    TransformableObject& TransformableObject::scale(const Vec3& scaleVector) {
        scaling = scaleVector;
        transform = glm::scale(transform, scaleVector);
        return *this;
    }

    TransformableObject& TransformableObject::setPosition(const Vec3& position) {
        transform = glm::translate(glm::mat4(1.0f), position);
        //transform = glm::rotate(transform, glm::radians(rotationAngle), rotation);
        transform = glm::scale(transform, scaling);
        return *this;
    }


} // namespace eng
