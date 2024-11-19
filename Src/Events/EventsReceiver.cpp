#include "EventsReceiver.hpp"
#include "GLFW/GLFW.hpp"

namespace TE::Events
{
    Ref<EventsReceiver> CreateEventsReceiver(TE::Core::ServiceAPIs api)
    {
        switch(api)
        {
            case TE::Core::ServiceAPIs::API_GLFW:     return CreateRef<TE::APIs::GLFW::GLFWAPI_EventReceiver>();
            case TE::Core::ServiceAPIs::API_SDL:      TRIMANA_ASSERT(TE_FALSE, "SDL is not supported yet.");
            case TE::Core::ServiceAPIs::API_WIN32:    TRIMANA_ASSERT(TE_FALSE, "None is not supported yet.");
            default:                                return nullptr;
        }
    }

}