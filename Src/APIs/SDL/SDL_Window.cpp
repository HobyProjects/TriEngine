#include "SDL_Window.hpp"
#include "Renderer.hpp"

namespace TE::APIs::SDL
{
    Boolean SDLServiceAPI::Init()
    {
        if(SDL_Init(SDL_INIT_VIDEO) < 0){
            TE_CORE_CRITICAL("SDL initialization failed: {0}", SDL_GetError());
            return false;
        }

        TE_CORE_INFO("SDL initialized successfully");
        TE_CORE_WARN("SDL init only for video subsystem");
        return true;
    }

    void SDLServiceAPI::Shutdown()
    {
        SDL_Quit();
    }

    SDLAPI_Window::SDLAPI_Window(const String& title)
    {
        SDL_DisplayID displayID = SDL_GetPrimaryDisplay();
        const SDL_DisplayMode* mode = SDL_GetCurrentDisplayMode(displayID);
        if(mode != nullptr)
        {
            m_Specification.Width               = mode->w;
            m_Specification.Height              = mode->h;
            m_Specification.FixedWidth          = mode->w;
            m_Specification.FixedHeight         = mode->h;
            m_Specification.MinWidth            = 1024;
            m_Specification.MinHeight           = 720;
            m_Specification.RedColorBits        = 8;
            m_Specification.GreenColorBits      = 8;
            m_Specification.BlueColorBits       = 8;
            m_Specification.AlphaColorBits      = 8;
            m_Specification.RefreshRate         = mode->refresh_rate;
        }
        else
        {
            TE_CORE_WARN("Failed to get primary display mode");
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

        if(TE::Renderer::Renderer::GetAPI() == TE::Renderer::RendererAPI::OpenGL)
        {
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
            SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
            SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, TE_TRUE);
            SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, TE_TRUE);

            SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
            SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
            SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
            SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
            SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
            SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
        }

        m_NativeWindow = SDL_CreateWindow(
            m_Specification.Title.c_str(),
            m_Specification.Width,
            m_Specification.Height,
            SDL_WINDOW_VULKAN | SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE
        );

        if(m_NativeWindow != nullptr)
        {
            TE_CORE_INFO("SDL window created successfully");
            SDL_SetWindowMaximumSize(m_NativeWindow, m_Specification.FixedWidth, m_Specification.FixedHeight);
            SDL_SetWindowMinimumSize(m_NativeWindow, m_Specification.MinWidth, m_Specification.MinHeight);
            SDL_GetWindowSizeInPixels(m_NativeWindow, &m_Specification.FramebufferWidth, &m_Specification.FramebufferHeight);

            m_Context = TE::Renderer::CreateContext(m_NativeWindow);
            m_Context->MakeContextCurrent();

            m_Specification.IsActive = true;
            m_Specification.IsVSyncEnabled = true;
            m_Specification.IsFocused = SDL_GetWindowFlags(m_NativeWindow) & SDL_WINDOW_INPUT_FOCUS;

            return;
        }

        TE_CORE_CRITICAL("Failed to create SDL window: {0}", SDL_GetError());
        SDL_Quit();
    }

    SDLAPI_Window::~SDLAPI_Window()
    {
        if(m_NativeWindow != nullptr)
            SDL_DestroyWindow(m_NativeWindow);
    }

    void SDLAPI_Window::SwapBuffers()
    {
        if(TE::Renderer::Renderer::GetAPI() == TE::Renderer::RendererAPI::OpenGL)
        {
            if(m_Specification.IsActive && m_Specification.IsVSyncEnabled)
                SDL_GL_SwapWindow(m_NativeWindow);
        }
    }
}