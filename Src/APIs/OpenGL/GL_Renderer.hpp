#pragma once

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "TypeDef.hpp"
#include "GL_Debug.hpp"

namespace TE::APIs::OpenGL
{
    class GL_Renderer
    {
        private:
            GL_Renderer() = default;
            ~GL_Renderer() = default;

        public:
            static void Init();
            static void Shutdown();
            static void Clear();
            static void ClearColor(const Vec4& color);
            static void SetViewport(UInt32 x, UInt32 y, UInt32 width, UInt32 height);
    };
}