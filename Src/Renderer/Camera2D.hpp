#pragma once

#include "TypeDef.hpp"
#include "Camera.hpp"

namespace TE::Renderer
{
    /**
     * @class Camera2D
     *
     * @brief A class to represent a 2D camera
     *
     * This class is used to represent a 2D camera. It provides functions to
     * calculate the view matrix, calculate the projection matrix, and get the
     * view projection matrix.
     */
    class Camera2D : public Camera
    {
        public:
            /**
             * @brief Default constructor
             *
             * Initializes the camera with a default size of 10.0f and a default
             * near and far clip value of -1.0f and 1.0f respectively.
             */
            Camera2D() = default;

            /**
             * @brief Constructor
             *
             * Initializes the camera with a specified size, near clip, and far
             * clip values.
             *
             * @param size The size of the camera.
             * @param nearClip The near clip value of the camera.
             * @param farClip The far clip value of the camera.
             */
            Camera2D(Float size = 10.0f, Float nearClip = -1.0f, Float farClip = 1.0f);

            /**
             * @brief Destructor
             *
             * Does nothing.
             */
            virtual ~Camera2D() = default;

            /**
             * @brief Gets the type of camera
             *
             * Returns the type of camera as CameraType::Camera_2D.
             *
             * @return The type of camera.
             */
            CameraType GetCameraType() const { return CameraType::Camera_2D; }

            /**
             * @brief Sets the aspect ratio of the camera
             *
             * Sets the aspect ratio of the camera to the specified value.
             *
             * @param ratio The aspect ratio of the camera.
             */
            void SetAspectRatio(Float ratio);

            /**
             * @brief Sets the rotation of the camera
             *
             * Sets the rotation of the camera to the specified value.
             *
             * @param rotation The rotation of the camera in degrees.
             */
            void SetRotation(Float rotation);

            /**
             * @brief Sets the position of the camera
             *
             * Sets the position of the camera to the specified value.
             *
             * @param position The position of the camera.
             */
            void SetPosition(const Vec3& position);

            /**
             * @brief Sets the projection of the camera
             *
             * Sets the projection of the camera to the specified values.
             *
             * @param size The size of the camera.
             * @param nearClip The near clip value of the camera.
             * @param farClip The far clip value of the camera.
             */
            void SetProjection(Float size = 10.0f, Float nearClip = -1.0f, Float farClip = 1.0f);

            /**
             * @brief Gets the view matrix of the camera
             *
             * Returns the view matrix of the camera.
             *
             * @return The view matrix of the camera.
             */
            const Mat4& GetView() const { return m_View; }

            /**
             * @brief Gets the projection matrix of the camera
             *
             * Returns the projection matrix of the camera.
             *
             * @return The projection matrix of the camera.
             */
            const Mat4& GetProjection() const { return m_Projection; }

            /**
             * @brief Gets the view projection matrix of the camera
             *
             * Returns the view projection matrix of the camera.
             *
             * @return The view projection matrix of the camera.
             */
            const Mat4& GetViewProjection() const { return m_ViewProjection; }

            /**
             * @brief Gets the size of the camera
             *
             * Returns the size of the camera.
             *
             * @return The size of the camera.
             */
            Float GetSize() const { return m_OrthographicSize; }

            /**
             * @brief Gets the near clip value of the camera
             *
             * Returns the near clip value of the camera.
             *
             * @return The near clip value of the camera.
             */
            Float GetNearClip() const { return m_OrthographicNear; }

            /**
             * @brief Gets the far clip value of the camera
             *
             * Returns the far clip value of the camera.
             *
             * @return The far clip value of the camera.
             */
            Float GetFarClip() const { return m_OrthographicFar; }

        private:
            /**
             * @brief Refreshes the view projection matrix
             *
             * Recalculates the view projection matrix based on the current
             * camera properties.
             */
            void RefreshViewProjectionMatrix();

        private:
            /**
             * @brief The aspect ratio of the camera
             *
             * The aspect ratio of the camera.
             */
            Float m_AspectRatio{1.0f};

            /**
             * @brief The size of the camera
             *
             * The size of the camera.
             */
            Float m_OrthographicSize{10.0f};

            /**
             * @brief The near clip value of the camera
             *
             * The near clip value of the camera.
             */
            Float m_OrthographicNear{-1000.0f};

            /**
             * @brief The far clip value of the camera
             *
             * The far clip value of the camera.
             */
            Float m_OrthographicFar{1000.0f};

            /**
             * @brief The view projection matrix of the camera
             *
             * The view projection matrix of the camera.
             */
            Mat4 m_ViewProjection{1.0f};
    };

}