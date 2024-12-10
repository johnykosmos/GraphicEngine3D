#include "Camera.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/trigonometric.hpp>
#include <glm/ext/matrix_clip_space.hpp>

namespace eng{
    
    Camera::Camera(Vec3 startPosition, float startYaw, float startPitch) 
        : position(startPosition), yaw(startYaw), pitch(startPitch) {

        fov = 45.0f;
        aspectRatio = 4.0f/3.0f;
        up = glm::vec3(0.0f, 1.0f, 0.0f); // Common up vector
        updateCameraVectors();
        updateViewProjection();
    }

    void Camera::updateCameraVectors(){
        Vec3 front;
        front.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
        front.y = sin(glm::radians(pitch));
        front.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
        this->front = glm::normalize(front);

        this->right = glm::normalize(glm::cross(front, up));
    }

    void Camera::updateViewProjection(){
        auto view = glm::lookAt(position, position + front, up);
        auto projection = glm::perspective(glm::radians(fov), 
                aspectRatio, 0.1f, 100.0f);
        viewProjection = projection * view;
    }


    Vec3 Camera::getPosition() const {
        return position;
    }

    float Camera::getYaw() const {
        return yaw;
    }

    float Camera::getPitch() const {
        return pitch;
    }

    const Vec3 Camera::getFront() const {
        return front;
    }

    const Vec3 Camera::getRight() const {
        return right;
    }

    glm::mat4 Camera::getViewProjection() const{
        return viewProjection;
    }

    void Camera::setPosition(const Vec3& newPosition) {
        position = newPosition;
        updateViewProjection();
    }

    void Camera::setYaw(float newYaw) {
        yaw = newYaw;
        updateCameraVectors();
        updateViewProjection();
    }

    void Camera::setPitch(float newPitch) {
        pitch = newPitch;
        updateCameraVectors();
        updateViewProjection();
    }
}

