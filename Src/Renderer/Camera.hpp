#pragma once 

#include "TypeDef.hpp"

namespace TE::Renderer
{

    /**
     * @enum CameraType
     *
     * @brief An enumeration to represent different types of cameras
     *
     * This enumeration is used to represent different types of cameras, such
     * as 2D and 3D cameras. It's used to determine the type of camera to
     * create when a Camera object is created.
     */
    enum class CameraType
    {
        /**
         * @brief A 2D camera
         *
         * A 2D camera is used to render 2D graphics. It doesn't have a
         * perspective, so it's not suitable for rendering 3D graphics.
         */
        Camera_2D = 0,

        /**
         * @brief A 3D camera
         *
         * A 3D camera is used to render 3D graphics. It has a perspective, so
         * it's suitable for rendering 3D graphics.
         */
        Camera_3D = 1
    };

    /**
     * @struct CameraBounds
     *
     * @brief A structure to represent the bounds of a camera
     *
     * This structure is used to represent the bounds of a camera. It's used to
     * calculate the view matrix and projection matrix of a camera. The bounds
     * are represented by the left, right, top, and bottom coordinates of the
     * camera's view.
     */
    struct CameraBounds
    {
        /**
         * @var Left
         *
         * @brief The left coordinate of the camera's view
         *
         * This is the leftmost coordinate of the camera's view. It's used to
         * calculate the view matrix and projection matrix of the camera.
         */
        Float Left{ 0.0f };

        /**
         * @var Right
         *
         * @brief The right coordinate of the camera's view
         *
         * This is the rightmost coordinate of the camera's view. It's used to
         * calculate the view matrix and projection matrix of the camera.
         */
        Float Right{ 0.0f };

        /**
         * @var Top
         *
         * @brief The top coordinate of the camera's view
         *
         * This is the topmost coordinate of the camera's view. It's used to
         * calculate the view matrix and projection matrix of the camera.
         */
        Float Top{ 0.0f };

        /**
         * @var Bottom
         *
         * @brief The bottom coordinate of the camera's view
         *
         * This is the bottommost coordinate of the camera's view. It's used to
         * calculate the view matrix and projection matrix of the camera.
         */
        Float Bottom{ 0.0f };

        /**
         * @brief Default constructor for CameraBounds
         *
         * This default constructor for CameraBounds initializes the left, right,
         * top, and bottom coordinates of the camera's view to 0.0. This is
         * useful for creating an empty CameraBounds object that can be used to
         * represent an empty camera view.
         */
        CameraBounds() = default;

        /**
         * @brief Constructor to create a CameraBounds object
         *
         * This constructor creates a CameraBounds object with the specified
         * left, right, top, and bottom coordinates.
         *
         * @param[in] left   The left coordinate of the camera's view
         * @param[in] right  The right coordinate of the camera's view
         * @param[in] top    The top coordinate of the camera's view
         * @param[in] bottom The bottom coordinate of the camera's view
         */
        CameraBounds(Float left, Float right, Float top, Float bottom) : Left(left), Right(right), Top(top), Bottom(bottom) {};

        /**
         * @brief Destructor to destroy a CameraBounds object
         *
         * This destructor is used to destroy a CameraBounds object.
         */
        ~CameraBounds() = default;

        /**
         * @brief Function to get the width of the camera's view
         *
         * This function returns the width of the camera's view, which is the
         * difference between the right and left coordinates of the camera's
         * view.
         *
         * @return The width of the camera's view
         */
        float Width() const { return Right - Left; }

        /**
         * @brief Function to get the height of the camera's view
         *
         * This function returns the height of the camera's view, which is the
         * difference between the bottom and top coordinates of the camera's
         * view.
         *
         * @return The height of the camera's view
         */
        float Height() const { return Bottom - Top; }
    };

    /**
     * @class Camera
     *
     * @brief A class to represent a camera
     *
     * This class is used to represent a camera. It provides functions to
     * calculate the view matrix, calculate the projection matrix, and get the
     * view projection matrix.
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
             * @brief Destructor
             *
             * Currently empty.
             */
            virtual ~Camera() = default;


        protected:

            /**
             * @brief The projection matrix of the camera
             *
             * This matrix is used to project points from view space onto the
             * screen. It is used in combination with the view matrix to
             * project 3D objects onto the screen.
             *
             * The projection matrix is a 4x4 matrix, where each element
             * represents the following:
             *
             *   - m00: The x-scaling factor.
             * 
             *   - m01: The x-skewing factor
             * 
             *   - m02: The x-translation factor
             * 
             *   - m03: The x-perspective factor
             * 
             *   - m10: The y-scaling factor
             * 
             *   - m11: The y-skewing factor
             * 
             *   - m12: The y-translation factor
             * 
             *   - m13: The y-perspective factor
             * 
             *   - m20: The z-scaling factor
             * 
             *   - m21: The z-skewing factor
             * 
             *   - m22: The z-translation factor
             * 
             *   - m23: The z-perspective factor
             * 
             *   - m30: The x-scaling factor
             * 
             *   - m31: The x-skewing factor
             * 
             *   - m32: The x-translation factor
             * 
             *   - m33: The x-perspective factor
             *
             * The projection matrix is initialized to the identity matrix,
             * which is a 4x4 matrix where all elements are 0 except for the
             * diagonal elements, which are all 1. This means that the
             * projection matrix does not perform any transformation on the
             * points it is applied to.
             */
            Mat4 m_Projection{1.0f};

            /**
             * @brief The view matrix of the camera
             *
             * This matrix is used to convert points from world space into view
             * space. It is used in combination with the projection matrix to
             * project 3D objects onto the screen.
             *
             * The view matrix is the inverse of the camera's transformation
             * matrix. It is used to convert points from world space into view
             * space, which is the coordinate system in which the camera is
             * located.
             *
             * The view matrix is represented as a 4x4 matrix, where each
             * element represents the following:
             *
             *   - m00: The x-scaling factor.
             * 
             *   - m01: The x-skewing factor
             * 
             *   - m02: The x-translation factor
             * 
             *   - m03: The x-perspective factor
             * 
             *   - m10: The y-scaling factor
             * 
             *   - m11: The y-skewing factor
             * 
             *   - m12: The y-translation factor
             * 
             *   - m13: The y-perspective factor
             * 
             *   - m20: The z-scaling factor
             * 
             *   - m21: The z-skewing factor
             * 
             *   - m22: The z-translation factor
             * 
             *   - m23: The z-perspective factor
             * 
             *   - m30: The x-translation factor
             * 
             *   - m31: The y-translation factor
             * 
             *   - m32: The z-translation factor
             * 
             *   - m33: The homogeneous coordinate
             *
             * The view matrix is typically represented as a column-major
             * matrix, meaning that the elements are arranged in column-major
             * order (i.e., the first column is the x-axis, the second column is
             * the y-axis, and the third column is the z-axis). This means that
             * the x-axis is represented by the first column, the y-axis is
             * represented by the second column, and the z-axis is represented
             * by the third column.
             */
            Mat4 m_View{1.0f};


            /**
             * @brief The position of the camera in world space
             *
             * This is a 3-element vector representing the position of the
             * camera in world space. The elements of the vector are:
             *
             *   - x: The x-coordinate of the camera in world space
             *   - y: The y-coordinate of the camera in world space
             *   - z: The z-coordinate of the camera in world space
             *
             * The position of the camera is used to calculate the view matrix,
             * which is used to convert points from world space into view space.
             * The view matrix is used in combination with the projection matrix
             * to project 3D objects onto the screen.
             */
            Vec3 m_Position{0.0f, 0.0f, 0.0f};

            /**
             * @brief The rotation angle of the camera in degrees
             *
             * This is a floating-point value representing the rotation angle
             * of the camera around the z-axis in world space. The rotation
             * is measured in degrees, where a positive value indicates a
             * counter-clockwise rotation and a negative value indicates a
             * clockwise rotation.
             *
             * The rotation is used to calculate the view matrix, which is
             * used to convert points from world space into view space. The
             * view matrix is used in combination with the projection matrix
             * to project 3D objects onto the screen.
             */
            Float m_Rotation{0.0f};
    };
}