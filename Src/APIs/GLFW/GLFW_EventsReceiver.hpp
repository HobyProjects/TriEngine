#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "EventsReceiver.hpp"

namespace TE::APIs::GLFW
{
    class GLFWAPI_EventReceiver : public TE::Events::IEventsReceiver
    {
        public:
            GLFWAPI_EventReceiver() = default;
            virtual ~GLFWAPI_EventReceiver() = default;
            void PollEvents() override;
            virtual void SetCallbackWindow(const Ref<TE::Core::Window>& window, const TE::Events::EventCallback& eventsCallback) override;
    };
}