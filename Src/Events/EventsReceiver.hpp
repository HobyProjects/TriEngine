#pragma once

#include "Window.hpp"
#include "WindowEvents.hpp"
#include "KeyboardEvents.hpp"
#include "MouseEvents.hpp"

namespace TE::Events
{
    /**
     * @class EventsReceiver
     *
     * @brief Abstract base class for any class that needs to receive events from the windowing API.
     *
     * This class is used to define the interface for any class that needs to receive events from the windowing API.
     * It provides a way to poll events from the window, as well as a way to set a callback function for events.
     *
     * @note The class is abstract, meaning that it cannot be instantiated directly. Any derived classes must
     * implement the pure virtual functions declared here.
     */
    class EventsReceiver
    {
        public:
            /**
             * @brief Constructor for the EventsReceiver class.
             *
             * This constructor is the default constructor for the EventsReceiver class.
             */
            EventsReceiver() = default;

            /**
             * @brief Virtual destructor for the EventsReceiver class.
             *
             * This destructor is used to destroy an EventsReceiver object. It is declared as virtual to ensure that
             * the correct destructor is called when deleting an object of a derived class.
             */
            virtual ~EventsReceiver() = default;

            /**
             * @brief Pure virtual function to poll events from the window.
             *
             * This function is used to poll events from the window. It is declared as pure virtual to ensure that
             * any derived classes must implement this function.
             */
            virtual void PollEvents() = 0;

            /**
             * @brief Pure virtual function to set a callback function for events.
             *
             * This function is used to set a callback function for events. The callback function will be called
             * whenever an event occurs in the window. The function takes two parameters: a shared pointer to a
             * Window object, and an EventCallback object.
             *
             * @param window A shared pointer to a Window object.
             * @param callBack An EventCallback object to be called when an event occurs.
             */
            virtual void SetCallbackWindow(const std::shared_ptr<TE::Core::Window>& window, const EventCallback& callBack) = 0;
    };

    /**
     * @brief Creates a new EventsReceiver object based on the specified window API.
     *
     * This function is used to create a new EventsReceiver object based on the specified window API. It returns a
     * shared pointer to the newly created object. The returned object can be used to poll events from the window
     * and to set a callback function for events.
     *
     * @param api The window API to use when creating the EventsReceiver object. The default value is
     * TE::Core::WindowAPI::GLFW_API.
     *
     * @return A shared pointer to the newly created EventsReceiver object.
     */
    std::shared_ptr<EventsReceiver> CreateEventsReceiver(TE::Core::WindowAPI api = TE::Core::WindowAPI::GLFW_API);
}