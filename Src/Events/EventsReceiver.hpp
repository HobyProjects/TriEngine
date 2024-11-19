#pragma once

#include "Window.hpp"
#include "WindowEvents.hpp"
#include "KeyboardEvents.hpp"
#include "MouseEvents.hpp"

namespace TE::Events
{
    class EventsReceiver
    {
        public:
            EventsReceiver() = default;
            virtual ~EventsReceiver() = default;

            virtual void PollEvents() = TE_NULL;
            virtual void SetCallbackWindow(const Ref<TE::Core::Window>& window, const EventCallback& callBack) = TE_NULL;
    };
    
    Ref<EventsReceiver> CreateEventsReceiver(TE::Core::ServiceAPIs api = TE::Core::ServiceAPIs::API_GLFW);
}