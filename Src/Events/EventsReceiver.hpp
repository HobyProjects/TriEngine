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
            virtual void SetCallbackWindow(const Ref<TE::Core::IWindow>& window, const EventCallback& callBack) = TE_NULL;
    };
    
    Ref<IEventsReceiver> CreateEventsReceiver(TE::Core::ServiceAPI api = TE::Core::ServiceAPI::API_GLFW);
}