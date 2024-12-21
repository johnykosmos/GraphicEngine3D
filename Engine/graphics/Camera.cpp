#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/trigonometric.hpp>
#include <glm/ext/matrix_clip_space.hpp>

namespace eng{
    
    PerspectiveCamera::PerspectiveCamera(Vec3 startPosition, float aspectRatio, float startYaw, float startPitch)  
        : position(startPosition), aspectRatio(aspectRatio), yaw(startYaw), pitch(startPitch) {

        fov = 45.0f;
        up = Vec3(0.0f, 1.0f, 0.0f); // Common up vector
        updateCameraVectors();
        updateViewProjection();
    }

    void PerspectiveCamera::updateCameraVectors(){
        Vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        this->front = glm::normalize(front);

        this->right = glm::normalize(glm::cross(front, up));
    }

    void PerspectiveCamera::updateViewProjection(){
        auto view = glm::lookAt(position, position + front, up);
        auto projection = glm::perspective(glm::radians(fov), 
                aspectRatio, 0.1f, 100.0f);
        viewProjection = projection * view;
    }


    Vec3 PerspectiveCamera::getPosition() const {
        return position;
    }

    float PerspectiveCamera::getYaw() const {
        return yaw;
    }

    float PerspectiveCamera::getPitch() const {
        return pitch;
    }

    const Vec3 PerspectiveCamera::getFront() const {
        return front;
    }

    const Vec3 PerspectiveCamera::getRight() const {
        return right;
    }

    Mat4 PerspectiveCamera::getViewProjection() const{
        return viewProjection;
    }

    void PerspectiveCamera::setPosition(const Vec3& newPosition) {
        position = newPosition;
        updateViewProjection();
    }

    void PerspectiveCamera::setYaw(float newYaw) {
        yaw = newYaw;
        updateCameraVectors();
        updateViewProjection();
    }

    void PerspectiveCamera::setPitch(float newPitch) {
        pitch = newPitch;
        updateCameraVectors();
        updateViewProjection();
    }
}

