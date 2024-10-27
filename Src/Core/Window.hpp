#pragma once

#include <string>
#include <memory>

#include "OpenGL/OpenGL.hpp"
#include "Renderer.hpp"
#include "Context.hpp"
#include "TypeDef.hpp"

namespace TE::Core
{

    enum class WindowState
    {
        Minimized = 0,  
        Maximized = 1,  
        Normal    = 2  
    };

    struct WindowSpecification
    {
        UInt32 Width{0};                           
        UInt32 Height{0};                          
        Boolean IsVSyncEnabled{TE_NULL};           
        Boolean IsActive{TE_NULL};                 
        Boolean IsFocused{TE_NULL};                
        UInt32 RedColorBits{8};               
        UInt32 GreenColorBits{8};             
        UInt32 BlueColorBits{8};              
        UInt32 AlphaColorBits{8};             
        UInt32 DepthColorBits{24};            
        UInt32 StencilColorBits{8};           
        UInt32 RefreshRate{60};               
        UInt32 FixedWidth{TE_NULL};           
        UInt32 FixedHeight{TE_NULL};          
        UInt32 MinWidth{1280};                
        UInt32 MinHeight{720};                
        UInt32 PosX{TE_NULL};                 
        UInt32 PosY{TE_NULL};                 
        Int32 FramebufferWidth{TE_NULL};      
        Int32 FramebufferHeight{TE_NULL};     
        WindowState WindowState{WindowState::Normal};   
        String Title{String()};                    
    };

    enum class ServiceAPI
    {
        API_None        = TE_BIT(0),
        API_GLFW        = TE_BIT(1),
        API_SDL         = TE_BIT(2),
        API_WIN32       = TE_BIT(3),
    };

    class IServiceAPI
    {
        public:
            IServiceAPI() = default;
            virtual ~IServiceAPI() = default;

            virtual Boolean Init() = TE_NULL;
            virtual void Shutdown() = TE_NULL;
            virtual ServiceAPI GetAPI() = TE_NULL;
    };

    class IWindow
    {
        public:
            IWindow() = default;
            ~IWindow() = default;

            virtual NativeWindow GetNativeWindow() = TE_NULL;
            virtual WindowSpecification& GetWindowSpecification() = TE_NULL;
            virtual Ref<TE::Renderer::IContext> GetContext() = TE_NULL;
            virtual void SwapBuffers() = TE_NULL;
    };

    Ref<IWindow> CreateWindow(const String& title, ServiceAPI api = ServiceAPI::API_GLFW);
}