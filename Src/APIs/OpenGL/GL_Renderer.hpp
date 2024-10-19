#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "TypeDef.hpp"
#include "GL_Debug.hpp"

namespace TE::APIs::OpenGL
{
    /**
     * @class GL_Renderer
     *
     * @brief A class to represent the OpenGL renderer
     *
     * This class is used to represent the OpenGL renderer. It provides
     * functions to initialize and shut down the renderer, clear the screen,
     * set the clear color, and set the viewport.
     */
    class GL_Renderer
    {
        private:
            /**
             * @brief Private constructor
             *
             * This constructor is left private to prevent external code from
             * directly constructing the class. This is done to enforce the
             * singleton pattern.
             */
            GL_Renderer() = default;

            /**
             * @brief Private destructor
             *
             * This destructor is left private to prevent external code from
             * directly destroying the class. This is done to enforce the
             * singleton pattern.
             */
            ~GL_Renderer() = default;

        public:
            /**
             * @brief Initializes the renderer
             *
             * This function initializes the renderer. It is called by the
             * engine when it starts up.
             */
            static void Init();

            /**
             * @brief Shuts down the renderer
             *
             * This function shuts down the renderer. It is called by the
             * engine when it shuts down.
             */
            static void Shutdown();

            /**
             * @brief Clears the screen
             *
             * This function clears the screen. It is called by the engine
             * during each frame.
             */
            static void Clear();

            /**
             * @brief Sets the clear color
             *
             * This function sets the clear color. It is called by the engine
             * during each frame.
             *
             * @param color The color to set
             */
            static void ClearColor(const glm::vec4 & color);

            /**
             * @brief Sets the viewport
             *
             * This function sets the viewport. It is called by the engine
             * during each frame.
             *
             * @param x The x-coordinate of the viewport
             * @param y The y-coordinate of the viewport
             * @param width The width of the viewport
             * @param height The height of the viewport
             */
            static void SetViewport(UInt32 x, UInt32 y, UInt32 width, UInt32 height);
    };
}