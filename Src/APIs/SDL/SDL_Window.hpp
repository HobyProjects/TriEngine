#pragma once 

#include "SDL3/SDL.h"

#include "Window.hpp"
#include "Context.hpp"

namespace TE::APIs::SDL
{
    class SDLServiceAPI : public TE::Core::ServiceAPI
    {
        public:
            SDLServiceAPI() = default;
            virtual ~SDLServiceAPI() = default;

            virtual Boolean Init() override;
            virtual void Shutdown() override;
            virtual TE::Core::ServiceAPIs GetAPI() override{ return TE::Core::ServiceAPIs::API_SDL; }
    };

    class SDLAPI_Window : public TE::Core::Window
    {
        public:
            SDLAPI_Window(const String& title);
            virtual ~SDLAPI_Window();
            virtual NativeWindow GetNativeWindow() override { return (NativeWindow)m_NativeWindow; }
            virtual TE::Core::WindowSpecification& GetWindowSpecification() override { return m_Specification; }
            virtual Ref<TE::Renderer::Context> GetContext() override { return m_Context; }
            virtual void SwapBuffers() override;
            
        private:
            SDL_Window* m_NativeWindow{nullptr};
            TE::Core::WindowSpecification m_Specification{};
            Ref<TE::Renderer::Context> m_Context{nullptr};
    };
}