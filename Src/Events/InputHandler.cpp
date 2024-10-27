#include "InputHandler.hpp"
#include "GLFW/GLFW.hpp"

namespace TE::Events
{
    Ref<TE::Events::IInputHandler> TE::Events::CreateInputHandler(TE::Core::ServiceAPI api)
    {
        switch(api)
        {
            case TE::Core::ServiceAPI::API_GLFW:     return CreateRef<TE::APIs::GLFW::GLFWAPI_InputHandler>();
            case TE::Core::ServiceAPI::API_SDL:      TRIMANA_ASSERT(TE_FALSE, "SDL is not supported yet.");
            case TE::Core::ServiceAPI::API_WIN32:    TRIMANA_ASSERT(TE_FALSE, "None is not supported yet.");
            default:                                return nullptr;
        };
    }

}