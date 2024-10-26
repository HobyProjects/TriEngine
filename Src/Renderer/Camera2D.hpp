#pragma once

#include "TypeDef.hpp"

namespace TE::Renderer
{
    /**
     * @class Camera2D
     *
     * @brief A class that represents a 2D camera
     *
     * This class is used to represent a 2D camera. It provides functions to
     * set the rotation and position of the camera, set the projection of the
     * camera, and get the view matrix, projection matrix, and view projection
     * matrix.
     */
    class Camera2D 
    {
        public:
            /**
             * @brief Default constructor
             *
             * The default constructor initializes the camera with a default
             * projection and a default position and rotation.
             */
            Camera2D() = default;

            /**
             * @brief Constructor that takes a left, right, bottom, and top
             *
             * This constructor initializes the camera with the given left,
             * right, bottom, and top values for the projection. The position
             * and rotation are set to the default values.
             *
             * @param left The left side of the projection
             * @param right The right side of the projection
             * @param bottom The bottom side of the projection
             * @param top The top side of the projection
             */
            Camera2D(float left, float right, float bottom, float top);

            /**
             * @brief Destructor
             *
             * The destructor is trivial and does nothing.
             */
            ~Camera2D() = default;

            /**
             * @brief Sets the rotation of the camera
             *
             * This function sets the rotation of the camera to the given
             * value.
             *
             * @param rotation The new rotation of the camera
             */
            void SetRotation(float rotation);

            /**
             * @brief Sets the position of the camera
             *
             * This function sets the position of the camera to the given
             * value.
             *
             * @param position The new position of the camera
             */
            void SetPosition(const Vec3& position);

            /**
             * @brief Sets the projection of the camera
             *
             * This function sets the projection of the camera to the given
             * left, right, bottom, and top values.
             *
             * @param left The left side of the projection
             * @param right The right side of the projection
             * @param bottom The bottom side of the projection
             * @param top The top side of the projection
             */
            void SetProjection(float left, float right, float bottom, float top);

            /**
             * @brief Gets the view matrix
             *
             * This function returns a reference to the view matrix of the
             * camera.
             *
             * @return A reference to the view matrix
             */
            const Mat4& ViewMatrix() const { return m_View; }

            /**
             * @brief Gets the projection matrix
             *
             * This function returns a reference to the projection matrix of
             * the camera.
             *
             * @return A reference to the projection matrix
             */
            const Mat4& ProjectionMatrix() const { return m_Projection; }

            /**
             * @brief Gets the view projection matrix
             *
             * This function returns a reference to the view projection matrix
             * of the camera.
             *
             * @return A reference to the view projection matrix
             */
            const Mat4& ViewProjectionMatrix() const { return m_ViewProjection; }

        private:
            /**
             * @brief Recalculates the view matrix
             *
             * This function is used to recalculate the view matrix when the
             * position or rotation of the camera changes.
             */
            void RecalculateViewMatrix();

        private:
            /**
             * @brief The view matrix
             *
             * This is the view matrix of the camera. It is recalculated when
             * the position or rotation of the camera changes.
             */
            Mat4 m_View{1.0f};

            /**
             * @brief The projection matrix
             *
             * This is the projection matrix of the camera. It is set when the
             * camera is created and can be changed with the SetProjection
             * function.
             */
            Mat4 m_Projection{1.0f};

            /**
             * @brief The view projection matrix
             *
             * This is the view projection matrix of the camera. It is
             * calculated by multiplying the view matrix and the projection
             * matrix.
             */
            Mat4 m_ViewProjection{1.0f};

            /**
             * @brief The position of the camera
             *
             * This is the position of the camera. It can be changed with the
             * SetPosition function.
             */
            Vec3 m_Position{0.0f};

            /**
             * @brief The rotation of the camera
             *
             * This is the rotation of the camera. It can be changed with the
             * SetRotation function.
             */
            float m_Rotation{0.0f};
    };

}