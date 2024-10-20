#pragma once

#include <sstream>
#include <glad/glad.h>
#include "TypeDef.hpp"

namespace TE::APIs::OpenGL
{
    /**
     * @class GL_SystemInfo
     *
     * @brief A class to provide information about the OpenGL system
     *
     * This class contains static functions to retrieve information about the OpenGL system,
     * including the vendor, renderer, version, and GLSL version.
     */
    class GL_SystemInfo
    {
    private:
        /**
         * @brief Private constructor
         *
         * Default private constructor to prevent external instantiation of the class.
         */
        GL_SystemInfo() = default;

        /**
         * @brief Private destructor
         *
         * Default private destructor to prevent external deletion of the class.
         */
        ~GL_SystemInfo() = default;

    public:
        /**
         * @brief Get the vendor of the OpenGL system
         *
         * @return A string representing the vendor of the OpenGL system
         */
        static String GetVendor();

        /**
         * @brief Get the renderer of the OpenGL system
         *
         * @return A string representing the renderer of the OpenGL system
         */
        static String GetRenderer();

        /**
         * @brief Get the version of the OpenGL system
         *
         * @return A string representing the version of the OpenGL system
         */
        static String GetVersion();

        /**
         * @brief Get the GLSL version of the OpenGL system
         *
         * @return A string representing the GLSL version of the OpenGL system
         */
        static String GetGLSLVersion();

    };
}