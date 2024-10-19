#include "EventsReceiver.hpp"
#include "GLFW.hpp"

namespace TE::Events
{
    std::shared_ptr<EventsReceiver> CreateEventsReceiver(TE::Core::WindowAPI api)
    {
        switch(api)
        {
            case TE::Core::WindowAPI::GLFW_API:     return std::make_shared<TE::APIs::GLFW::GLFW_EventsReceiver>();
            default:                                return nullptr;
        }
    }

}