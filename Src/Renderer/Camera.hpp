#pragma once 

#include "TypeDef.hpp"

namespace TE::Renderer
{
    /**
     * @class Camera
     *
     * @brief A class that represents a camera in a 3D scene
     *
     * This class is used to represent a camera in a 3D scene. It contains the
     * projection matrix of the camera, which is used to project 3D objects onto
     * the screen.
     *
     * The camera is set up so that the x-axis points right, the y-axis points
     * up, and the z-axis points out of the screen. The camera's position is at
     * the origin (0, 0, 0) and it is looking at the negative z-axis.
     *
     * The class contains two constructors: a default constructor and a
     * constructor that takes a Mat4 argument representing the projection
     * matrix of the camera. The default constructor initializes the projection
     * matrix to the identity matrix.
     *
     * The class also contains a destructor, which is currently empty.
     *
     * The class contains one public method: GetProjectionMatrix(), which
     * returns a reference to the projection matrix of the camera.
     *
     * The class also contains one protected member variable: m_Projection, which
     * is the projection matrix of the camera.
     */
    class Camera
    {
        public:
            /**
             * @brief Default constructor
             *
             * Initializes the projection matrix to the identity matrix.
             */
            Camera() = default;

            /**
             * @brief Constructor that takes a projection matrix
             *
             * Initializes the projection matrix to the provided matrix.
             *
             * @param projection The projection matrix
             */
            Camera(const Mat4& projection) : m_Projection(projection) {}

            /**
             * @brief Destructor
             *
             * Currently empty.
             */
            ~Camera() = default;

            /**
             * @brief Returns a reference to the projection matrix of the camera
             *
             * @return A reference to the projection matrix
             */
            const Mat4& GetProjectionMatirx() const { return m_Projection; }

        protected:

            /**
             * @brief The projection matrix of the camera
             *
             * This matrix is used to project 3D objects onto the screen.
             */
            Mat4 m_Projection{1.0f};
    };
}