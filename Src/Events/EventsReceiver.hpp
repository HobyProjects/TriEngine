#pragma once

#include "Window.hpp"
#include "WindowEvents.hpp"
#include "KeyboardEvents.hpp"
#include "MouseEvents.hpp"

namespace TE::Events
{
    class IEventsReceiver
    {
        public:
            IEventsReceiver() = default;
            virtual ~IEventsReceiver() = default;

            virtual void PollEvents() = TE_NULL;
            virtual void SetCallbackWindow(const Ref<TE::Core::Window>& window, const EventCallback& callBack) = TE_NULL;
    };
    
    Ref<IEventsReceiver> CreateEventsReceiver(TE::Core::ServiceAPIs api = TE::Core::ServiceAPIs::API_GLFW);
}