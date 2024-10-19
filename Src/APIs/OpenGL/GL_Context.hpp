#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Context.hpp"
#include "TypeDef.hpp"

namespace TE::APIs::OpenGL
{
    /**
     * @brief A class to represent an OpenGL rendering context
     *
     * This class is used to represent an OpenGL rendering context. It
     * provides functions to make the context current, swap buffers, and
     * change the swap interval.
     */
    class GL_Context : public TE::Renderer::Context
    {
        public:
            /**
             * @brief Default constructor
             *
             * This function is the default constructor for the GL_Context
             * class.
             */
            GL_Context() = default;

            /**
             * @brief Constructor
             *
             * This function is a constructor for the GL_Context class. It
             * takes a GLFW window as a parameter and uses it to create an
             * OpenGL rendering context.
             *
             * @param window A GLFW window
             */
            GL_Context(GLFWwindow* window);

            /**
             * @brief Destructor
             *
             * This function is the destructor for the GL_Context class.
             */
            virtual ~GL_Context() = default;

            /**
             * @brief Make the context current
             *
             * This function is used to make the context current. This means
             * that the context is selected as the current OpenGL rendering
             * context.
             *
             * @return True if the context was made current, false otherwise
             */
            virtual bool MakeContextCurrent() override;

            /**
             * @brief Swap the front and back buffers
             *
             * This function is used to swap the front and back buffers. This
             * causes the rendered image to be presented to the user.
             */
            virtual void SwapBuffers() override;

            /**
             * @brief Change the swap interval
             *
             * This function is used to change the swap interval. The swap
             * interval is the number of screen updates that must occur before
             * the buffers are swapped. A swap interval of 0 causes the buffers
             * to be swapped immediately, while a swap interval of 1 causes
             * the buffers to be swapped only after a screen update has
             * occurred.
             *
             * @param interval The new swap interval
             */
            virtual void ChangeSwapInterval(UInt32 interval) override;

        private:
            /**
             * @brief The GLFW window
             *
             * This is the GLFW window that is used to create the OpenGL
             * rendering context.
             */
            GLFWwindow* m_Window{nullptr};
    };
}