#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Window.hpp"
#include "Context.hpp"

namespace TE::APIs::GLFW
{
    class GLFWServiceAPI : public TE::Core::ServiceAPI
    {
        public:
            GLFWServiceAPI() = default;
            virtual ~GLFWServiceAPI() = default;

            virtual Boolean Init() override;
            virtual void Shutdown() override;
            virtual TE::Core::ServiceAPIs GetAPI() override{ return TE::Core::ServiceAPIs::API_GLFW; }
    };

    class GLFWAPI_Window : public TE::Core::Window
    {
        public:
            GLFWAPI_Window(const String& title);
            virtual ~GLFWAPI_Window();

            virtual NativeWindow GetNativeWindow() override { return (NativeWindow)m_NativeWindow; }
            virtual TE::Core::WindowSpecification& GetWindowSpecification() override { return m_Specification; }
            virtual Ref<TE::Renderer::Context> GetContext() override { return m_Context; }
            virtual void SwapBuffers() override;

        private:
            GLFWwindow* m_NativeWindow{nullptr};
            TE::Core::WindowSpecification m_Specification{};
            Ref<TE::Renderer::Context> m_Context{nullptr};
    };
}