#include "Window.hpp"

namespace TE::Core
{
    Window::Window(const String& title)
    {
        if(glfwInit()){
            TE_CORE_CRITICAL("GLFW: Failed to initialize");
            return;
        }

        TE_CORE_INFO("GLFW: Initialized");
        const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
        if(mode != nullptr)
        {
            m_Specification.Width               = mode->width;
            m_Specification.Height              = mode->height;
            m_Specification.FixedWidth          = mode->width;
            m_Specification.FixedHeight         = mode->height;
            m_Specification.MinWidth            = 1024;
            m_Specification.MinHeight           = 720;
            m_Specification.RedColorBits        = mode->redBits;
            m_Specification.GreenColorBits      = mode->greenBits;
            m_Specification.BlueColorBits       = mode->blueBits;
            m_Specification.AlphaColorBits      = 8;
            m_Specification.RefreshRate         = mode->refreshRate;
        }
        else 
        {
            TE_CORE_WARN("Failed to get primary monitor video mode");;
            m_Specification.Width           = 1280;
            m_Specification.Height          = 720;
            m_Specification.FixedWidth      = 0;
            m_Specification.FixedHeight     = 0;
            m_Specification.MinWidth        = 1024;
            m_Specification.MinHeight       = 720;
            m_Specification.RedColorBits    = 8;
            m_Specification.GreenColorBits  = 8;
            m_Specification.BlueColorBits   = 8;
            m_Specification.AlphaColorBits  = 8;
            m_Specification.RefreshRate     = 60;
        }

        m_Specification.Title = title;

        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GLFW_TRUE);
        glfwWindowHint(GLFW_DOUBLEBUFFER, GLFW_TRUE);

        glfwWindowHint(GLFW_RED_BITS, m_Specification.RedColorBits);
        glfwWindowHint(GLFW_GREEN_BITS, m_Specification.GreenColorBits);
        glfwWindowHint(GLFW_BLUE_BITS, m_Specification.BlueColorBits);
        glfwWindowHint(GLFW_ALPHA_BITS, m_Specification.AlphaColorBits);
        glfwWindowHint(GLFW_REFRESH_RATE, m_Specification.RefreshRate);
        glfwWindowHint(GLFW_DEPTH_BITS, 24);
        glfwWindowHint(GLFW_STENCIL_BITS, 8);

        m_NativeWindow = glfwCreateWindow(m_Specification.Width, m_Specification.Height, title.c_str(), nullptr, nullptr);
        if(m_NativeWindow != nullptr)
        {
            TE_CORE_INFO("GLFW window created");
            glfwSetWindowSizeLimits(m_NativeWindow, m_Specification.MinWidth, m_Specification.MinHeight, GLFW_DONT_CARE, GLFW_DONT_CARE);
            glfwGetFramebufferSize(m_NativeWindow, &m_Specification.FramebufferWidth, &m_Specification.FramebufferHeight);

            if(TE::Renderer::Renderer::GetAPI() == TE::Renderer::RendererAPI::OpenGL)
            {
                m_Context = std::make_shared<TE::APIs::OpenGL::GL_Context>(m_NativeWindow);
                if(m_Context->MakeContextCurrent())
                    TE_CORE_INFO("GLFW OpenGL context created");
                else
                    TE_CORE_CRITICAL("Failed to create GLFW OpenGL context");
            }

            if(TE::Renderer::Renderer::GetAPI() == TE::Renderer::RendererAPI::Vulkan)
            {
                TRIMANA_ASSERT(false, "Not implemented yet");
            }

            if(TE::Renderer::Renderer::GetAPI() == TE::Renderer::RendererAPI::DirectX)
            {
                TRIMANA_ASSERT(false, "Not implemented yet");
            }
     
            m_Specification.IsActive = true;
            m_Specification.IsFocused = glfwGetWindowAttrib(m_NativeWindow, GLFW_FOCUSED);
            m_Specification.IsVSyncEnabled = true;
            return;
        }

        TE_CORE_CRITICAL("Failed to create GLFW window");
        glfwTerminate();
    }

    Window::~Window()
    {
        if(m_NativeWindow != nullptr)
            glfwDestroyWindow(m_NativeWindow);
            
        glfwTerminate();
    }

    void Window::SwapBuffers()
    {
        if(m_Specification.IsActive && m_Specification.IsVSyncEnabled)
            m_Context->SwapBuffers();
    }
}