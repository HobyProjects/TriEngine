#include "Window.hpp"

#include "GLFW/GLFW.hpp"

namespace TE::Core
{
    Ref<IWindow> CreateWindow(const String& title, ServiceAPI api)
    {
        switch(api)
        {
            case ServiceAPI::API_GLFW:               return CreateRef<TE::APIs::GLFW::GLFWAPI_Window>(title);
            case ServiceAPI::API_SDL:                TRIMANA_ASSERT(TE_FALSE, "SDL is not supported yet!");
            default:                                return nullptr;
        }
    };
}