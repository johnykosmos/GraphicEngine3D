
#pragma once

#include <glm/mat4x4.hpp>
#include "Typedefs.hpp"

namespace eng {

    /**
     * @class Camera
     * @brief Abstract base class for cameras in a 3D graphics system.
     *
     * The Camera class provides an interface for deriving different types
     * of cameras. It includes a virtual destructor and a pure virtual method
     * for retrieving the view-projection matrix.
     */
    class Camera {
    public:
        /**
         * @brief Virtual destructor for Camera.
         *
         * Ensures proper cleanup of derived classes.
         */
        virtual ~Camera() = default;

        /**
         * @brief Retrieves the combined view and projection matrix.
         *
         * This pure virtual method must be implemented by derived classes.
         * @return The view-projection matrix as a glm::mat4.
         */
        virtual Mat4 getViewProjection() const = 0;

        /**
         * @brief Retrieves the position vector.
         *
         * This pure virtual method must be implemented by derived classes.
         * @return The position as a glm::vec3.
         */
        virtual Vec3 getPosition() const = 0;
    };

    /**
     * @class PerspectiveCamera
     * @brief Represents a perspective projection camera in a 3D graphics system.
     *
     * PerspectiveCamera manages the position, orientation, and perspective projection
     * parameters of a camera in 3D space. It calculates view and projection matrices
     * to enable 3D scene rendering.
     */
    class PerspectiveCamera : public Camera {
    private:
        Vec3 position;       ///< The position of the camera in 3D space.

        float fov;           ///< The field of view (FOV) in degrees for perspective projection.
        float aspectRatio;   ///< The aspect ratio of the screen (width/height).

        float yaw;           ///< The yaw angle (rotation around the Y-axis) in degrees.
        float pitch;         ///< The pitch angle (rotation around the X-axis) in degrees.

        Vec3 front;          ///< The front vector representing the camera's forward direction.
        Vec3 up;             ///< The up vector representing the camera's upward direction.
        Vec3 right;          ///< The right vector perpendicular to front and up vectors.

        Mat4 viewProjection; ///< Combined view and projection matrix.

        /**
         * @brief Updates the camera's front, right, and up vectors.
         *
         * Recalculates these vectors based on the yaw and pitch angles.
         */
        void updateCameraVectors();

        /**
         * @brief Updates the combined view and projection matrix.
         *
         * Recalculates the view-projection matrix based on the camera's current state.
         */
        void updateViewProjection();

    public:
        /**
         * @brief Constructs a PerspectiveCamera with a given position, yaw, and pitch.
         * @param startPosition The starting position of the camera.
         * @param aspectRatio The propotion between screen width and height
         * @param startYaw The initial yaw angle in degrees.
         * @param startPitch The initial pitch angle in degrees.
         */
        PerspectiveCamera(Vec3 startPosition, float aspectRatio, float startYaw, float startPitch);

        /**
         * @brief Retrieves the combined view and projection matrix.
         * @return The view-projection matrix as a Mat4.
         */
        Mat4 getViewProjection() const override;

        /**
         * @brief Retrieves the camera's current position.
         * @return The camera's position as a Vec3.
         */
        Vec3 getPosition() const override;

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
         * @return The front vector as a Vec3.
         */
        const Vec3 getFront() const;

        /**
         * @brief Retrieves the camera's right vector.
         * @return The right vector as a Vec3.
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

