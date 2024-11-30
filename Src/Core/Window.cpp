#include "Window.hpp"

#include "GLFW/GLFW.hpp"

namespace TE::Core
{
    static Boolean s_ServiceAPIInitialized = TE_FALSE;
    static Ref<ServiceAPI> s_ServiceAPI = nullptr;

    Ref<ServiceAPI> GetPlatformServiceAPI()
    {
        #ifdef TRIMANA_PLATFORM_WINDOWS
            //TODO: This should Win32 API, for now it's GLFW
            if(!s_ServiceAPIInitialized)
            {
                s_ServiceAPI = CreateRef<TE::APIs::GLFW::GLFWServiceAPI>();
                s_ServiceAPIInitialized = TE_TRUE;
            }
            return s_ServiceAPI;
        #endif

        #ifdef TRIMANA_PLATFORM_LINUX
            //FIXME: I don't know what is best API for Linux
            if(!s_ServiceAPIInitialized)
            {
                s_ServiceAPI = CreateRef<TE::APIs::GLFW::GLFWServiceAPI>();
                s_ServiceAPIInitialized = TE_TRUE;
            }
            return s_ServiceAPI;
        #endif

        #ifdef TRIMANA_PLATFORM_MAC
            //FIXME: I don't know what is best API for Mac
            if(!s_ServiceAPIInitialized)
            {
                s_ServiceAPI = CreateRef<TE::APIs::GLFW::GLFWServiceAPI>();
                s_ServiceAPIInitialized = TE_TRUE;
            }
            return s_ServiceAPI;
        #endif
    }

    Ref<Window> CreateWindow(const String& title, ServiceAPIs api)
    {
        switch(api)
        {
            case ServiceAPIs::API_GLFW:             return CreateRef<TE::APIs::GLFW::GLFWAPI_Window>(title);
            case ServiceAPIs::API_SDL:              TRIMANA_ASSERT(TE_FALSE, "SDL is not supported yet!");
            case ServiceAPIs::API_WIN32:            TRIMANA_ASSERT(TE_FALSE, "Win32 is not supported yet!");
            default:                                return nullptr;
        }
    };
}