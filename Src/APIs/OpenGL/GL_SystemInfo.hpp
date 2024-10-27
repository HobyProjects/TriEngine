#pragma once

#include <sstream>
#include <glad/glad.h>
#include "TypeDef.hpp"

namespace TE::APIs::OpenGL
{
    class GL_SystemInfo
    {
        private:
            GL_SystemInfo() = default;
            ~GL_SystemInfo() = default;

        public:
            static String GetVendor();
            static String GetRenderer();
            static String GetVersion();
            static String GetGLSLVersion();

    };
}