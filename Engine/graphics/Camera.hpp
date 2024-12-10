#pragma once

#include <glm/mat4x4.hpp>
#include "GLBuffers.hpp"


namespace eng{
    /**
     * @class Camera
     * @brief Represents a 3D camera that handles view and projection matrices.
     *
     * This class provides functionality to manage the camera position, orientation,
     * and perspective projection. It calculates the view matrix and projection matrix
     * to transform objects in the scene.
     */
    class Camera {
        private:
            Vec3 position;       ///< The position of the camera in 3D space.
            
            float fov;           ///< The field of view (FOV) in degrees for perspective projection.
            float aspectRatio;   ///< The aspect ratio of the screen (width/height).

            float yaw;           ///< The yaw angle (rotation around the Y-axis) in degrees.
            float pitch;         ///< The pitch angle (rotation around the X-axis) in degrees.

            Vec3 front;          ///< The front vector, representing the camera's forward direction.
            Vec3 up;             ///< The up vector, representing the camera's upward direction.
            Vec3 right;          ///< The right vector, perpendicular to front and up vectors.

            glm::mat4 viewProjection; ///< Combined view and projection matrix.

            /**
             * @brief Updates the camera's front, right, and up vectors based on the yaw and pitch angles.
             */
            void updateCameraVectors();

            /**
             * @brief Updates the combined view and projection matrix.
             */
            void updateViewProjection();

        public:
            /**
             * @brief Constructs a Camera with a given position, yaw, and pitch.
             * @param startPosition The starting position of the camera.
             * @param startYaw The initial yaw angle in degrees.
             * @param startPitch The initial pitch angle in degrees.
             */
            Camera(Vec3 startPosition, float startYaw, float startPitch);

            /**
             * @brief Retrieves the combined view and projection matrix.
             * @return The view-projection matrix as a glm::mat4.
             */
            glm::mat4 getViewProjection() const;

            /**
             * @brief Retrieves the camera's current position.
             * @return The camera's position as a Vec3.
             */
            Vec3 getPosition() const;

            /**
             * @brief Retrieves the camera's current yaw angle.
             * @return The yaw angle in degrees.
             */
            float getYaw() const;

            /**
             * @brief Retrieves the camera's current pitch angle.
             * @return The pitch angle in degrees.
             */
            float getPitch() const;

            /**
             * @brief Retrieves the camera's front vector (forward direction).
             * @return The front vector as a const Vec3.
             */
            const Vec3 getFront() const;

            /**
             * @brief Retrieves the camera's right vector.
             * @return The right vector as a const Vec3.
             */
            const Vec3 getRight() const;

            /**
             * @brief Sets the camera's yaw angle.
             * @param newYaw The new yaw angle in degrees.
             */
            void setYaw(float newYaw);

            /**
             * @brief Sets the camera's pitch angle.
             * @param newPitch The new pitch angle in degrees.
             */
            void setPitch(float newPitch);

            /**
             * @brief Sets the camera's position in 3D space.
             * @param newPosition The new position as a Vec3.
             */
            void setPosition(const Vec3& newPosition);
    };

}
