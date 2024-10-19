#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "EventsReceiver.hpp"

namespace TE::APIs::GLFW
{
    /**
     * @class GLFW_EventsReceiver
     *
     * @brief A class that acts as a receiver for GLFW events, and dispatches them to a callback function.
     *
     * This class is used to receive events from GLFW, and to dispatch them to a callback function. It is
     * responsible for polling the window for events, and to call the callback function when an event is
     * detected.
     */
    class GLFW_EventsReceiver : public TE::Events::EventsReceiver
    {
        public:
            /**
             * @brief Constructor for the GLFW_EventsReceiver class.
             *
             * This constructor is used to initialize the GLFW_EventsReceiver class.
             */
            GLFW_EventsReceiver() = default;

            /**
             * @brief Virtual destructor for the GLFW_EventsReceiver class.
             *
             * This destructor is used to destroy a GLFW_EventsReceiver object.
             */
            virtual ~GLFW_EventsReceiver() = default;

            /**
             * @brief Pure virtual function to poll events from the window.
             *
             * This function is used to poll events from the window. It is declared as pure virtual to ensure
             * that any derived classes must implement this function.
             */
            void PollEvents() override;

            /**
             * @brief Pure virtual function to set a callback function for events.
             *
             * This function is used to set a callback function for events. The callback function will be called
             * whenever an event occurs in the window. The function takes two parameters: a shared pointer to a
             * TE::Core::Window object, and an EventCallback object.
             *
             * @param window A shared pointer to a TE::Core::Window object.
             * @param callBack An EventCallback object to be called when an event occurs.
             */
            virtual void SetCallbackWindow(const std::shared_ptr<TE::Core::Window>& window, const TE::Events::EventCallback& eventsCallback) override;
    };
}