#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include "Context.hpp"
#include "TypeDef.hpp"

namespace TE::APIs::OpenGL
{
    class GL_Context : public TE::Renderer::Context
    {
        public:
            GL_Context() = default;
            GL_Context(GLFWwindow* window);
            virtual ~GL_Context() = default;

            virtual Boolean MakeContextCurrent() override;
            virtual void SwapBuffers() override;
            virtual void ChangeSwapInterval(UInt32 interval) override;

        private:
            GLFWwindow* m_Window{nullptr};
    };
}