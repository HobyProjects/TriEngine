#include "EventsReceiver.hpp"
#include "GLFW/GLFW.hpp"

namespace TE::Events
{
    Ref<IEventsReceiver> CreateEventsReceiver(TE::Core::ServiceAPI api)
    {
        switch(api)
        {
            case TE::Core::ServiceAPI::API_GLFW:     return CreateRef<TE::APIs::GLFW::GLFWAPI_EventReceiver>();
            case TE::Core::ServiceAPI::API_SDL:      TRIMANA_ASSERT(TE_FALSE, "SDL is not supported yet.");
            case TE::Core::ServiceAPI::API_WIN32:    TRIMANA_ASSERT(TE_FALSE, "None is not supported yet.");
            default:                                return nullptr;
        }
    }

}