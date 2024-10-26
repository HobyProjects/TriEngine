#pragma once

#include "TypeDef.hpp"
#include "Camera.hpp"

namespace TE::Renderer
{
    /**
     * @class Camera3D
     *
     * @brief A class to represent a 3D camera
     *
     * This class is used to represent a 3D camera. It provides functions to
     * calculate the view matrix, calculate the projection matrix, and get the
     * view projection matrix.
     */
    class Camera3D : public Camera
    {
        public:
            /**
             * @brief Default constructor
             *
             * Initializes the aspect ratio to 0.0f, the field of view to 45.0f
             * degrees, the near clipping plane to 0.01f units, and the far
             * clipping plane to 1000.0f units.
             */
            Camera3D() = default;

            /**
             * @brief Constructor
             *
             * Initializes the aspect ratio to the specified value, the field of
             * view to the specified value, the near clipping plane to the
             * specified value, and the far clipping plane to the specified
             * value.
             *
             * @param fov The field of view in degrees.
             * @param nearClip The near clipping plane in units.
             * @param farClip The far clipping plane in units.
             */
            Camera3D(Float fov = 45.0f, Float nearClip = 0.01f, Float farClip = 1000.0f);

            /**
             * @brief Destructor
             *
             * Currently empty.
             */
            virtual ~Camera3D() = default;

            /**
             * @brief Gets the type of camera
             *
             * @return The type of camera.
             */
            CameraType GetCameraType() const { return CameraType::Camera_3D; }

            /**
             * @brief Sets the aspect ratio of the camera
             *
             * @param ratio The aspect ratio of the camera.
             */
            void SetAspectRatio(Float ratio);

            /**
             * @brief Sets the rotation of the camera
             *
             * @param rotation The rotation of the camera in degrees.
             */
            void SetRotation(Float rotation);

            /**
             * @brief Sets the position of the camera
             *
             * @param position The position of the camera in world space.
             */
            void SetPosition(const Vec3& position);

            /**
             * @brief Sets the orientation of the camera
             *
             * @param orientation The orientation of the camera in world space.
             */
            void SetOrientation(const Vec3& orientation);

            /**
             * @brief Sets the up vector of the camera
             *
             * @param up The up vector of the camera in world space.
             */
            void SetPerspectiveUp(const Vec3& up);

            /**
             * @brief Sets the field of view, near clipping plane, and far clipping
             * plane of the camera
             *
             * @param fov The field of view in degrees.
             * @param nearClip The near clipping plane in units.
             * @param farClip The far clipping plane in units.
             */
            void SetPerspective(Float fov = 45.0f, Float nearClip = 0.01f, Float farClip = 1000.0f);

            /**
             * @brief Gets the position of the camera in world space
             *
             * @return The position of the camera in world space.
             */
            const Vec3& GetPosition() const { return m_Position; }

            /**
             * @brief Gets the orientation of the camera in world space
             *
             * @return The orientation of the camera in world space.
             */
            const Vec3& GetOrientation() const { return m_Orientation; }

            /**
             * @brief Gets the up vector of the camera in world space
             *
             * @return The up vector of the camera in world space.
             */
            const Vec3& GetPerspectiveUp() const { return m_PerspectiveUp; }

            /**
             * @brief Gets the view matrix of the camera
             *
             * @return The view matrix of the camera.
             */
            const Mat4& GetView() const { return m_View; }

            /**
             * @brief Gets the projection matrix of the camera
             *
             * @return The projection matrix of the camera.
             */
            const Mat4& GetProjection() const { return m_Projection; }

            /**
             * @brief Gets the view projection matrix of the camera
             *
             * @return The view projection matrix of the camera.
             */
            const Mat4& GetViewProjection() const { return m_ViewProjection; }

            /**
             * @brief Gets the field of view in degrees
             *
             * @return The field of view in degrees.
             */
            Float GetPerspectiveFov() const { return m_PerspectiveFov; }

            /**
             * @brief Gets the near clipping plane in units
             *
             * @return The near clipping plane in units.
             */
            Float GetPerspectiveNear() const { return m_PerspectiveNear; }

            /**
             * @brief Gets the far clipping plane in units
             *
             * @return The far clipping plane in units.
             */
            Float GetPerspectiveFar() const { return m_PerspectiveFar; }

            /**
             * @brief Gets the aspect ratio of the camera
             *
             * @return The aspect ratio of the camera.
             */
            Float GetAspectRatio() const { return m_AspectRatio; }

        private:
            /**
             * @brief Refreshes the view projection matrix
             *
             * This function is used to refresh the view projection matrix when
             * the camera is moved or rotated.
             */
            void RefreshViewProjectionMatrix();

        private:
            /**
             * @var m_ViewProjection
             *
             * @brief The view projection matrix of the camera
             *
             * This matrix is used to project points from view space onto the
             * screen. It is used in combination with the view matrix to
             * project 3D objects onto the screen.
             */
            Mat4 m_ViewProjection{1.0f};

            /**
             * @var m_Orientation
             *
             * @brief The orientation of the camera in world space
             *
             * This vector is used to represent the orientation of the camera in
             * world space. It is used to calculate the view matrix and
             * projection matrix of the camera.
             */
            Vec3 m_Orientation{0.0f, 0.0f, -1.0f};

            /**
             * @var m_PerspectiveUp
             *
             * @brief The up vector of the camera in world space
             *
             * This vector is used to represent the up vector of the camera in
             * world space. It is used to calculate the view matrix and
             * projection matrix of the camera.
             */
            Vec3 m_PerspectiveUp{0.0f, 1.0f, 0.0f};

            /**
             * @var m_AspectRatio
             *
             * @brief The aspect ratio of the camera
             *
             * This value is used to represent the aspect ratio of the camera. It
             * is used to calculate the projection matrix of the camera.
             */
            Float m_AspectRatio{0.0f};

            /**
             * @var m_PerspectiveFov
             *
             * @brief The field of view in degrees
             *
             * This value is used to represent the field of view of the camera in
             * degrees. It is used to calculate the projection matrix of the
             * camera.
             */
            Float m_PerspectiveFov{45.0f};

            /**
             * @var m_PerspectiveNear
             *
             * @brief The near clipping plane in units
             *
             * This value is used to represent the near clipping plane of the
             * camera in units. It is used to calculate the projection matrix of
             * the camera.
             */
            Float m_PerspectiveNear{0.01f};

            /**
             * @var m_PerspectiveFar
             *
             * @brief The far clipping plane in units
             *
             * This value is used to represent the far clipping plane of the
             * camera in units. It is used to calculate the projection matrix of
             * the camera.
             */
            Float m_PerspectiveFar{1000.0f};
    };

}