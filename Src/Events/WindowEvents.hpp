#pragma once

#include "Events.hpp"
#include "TypeDef.hpp"

namespace TE::Events
{
    /**
     * \brief Event class for handling the closing of the application window.
     * 
     * This class represents an event that occurs when the application window is being closed.
     */
    class AppWindowCloseEvent : public Event
    {
        public:
            /**
             * \brief Default constructor for AppWindowCloseEvent.
             */
            AppWindowCloseEvent() = default;

            /**
             * \brief Virtual destructor for AppWindowCloseEvent.
             */
            virtual ~AppWindowCloseEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application); ///< Set the event category to Application.
            EVENT_CLASS_TYPE(EventType::AppWindowCloseEvent); ///< Set the event type to AppWindowCloseEvent.
    };


    /**
     * \brief Event class for handling the resizing of the application window.
     * 
     * This class represents an event that occurs when the application window is being resized.
     */
    class AppWindowResizeEvent : public Event
    {
        public:
            /**
             * \brief Constructor for AppWindowResizeEvent.
             * 
             * \param width The new width of the application window.
             * \param height The new height of the application window.
             */
            AppWindowResizeEvent(UInt32 width, UInt32 height) : m_Width(width), m_Height(height) {}

            /**
             * \brief Virtual destructor for AppWindowResizeEvent.
             */
            virtual ~AppWindowResizeEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application); ///< Set the event category to Application.
            EVENT_CLASS_TYPE(EventType::AppWindowResizeEvent); ///< Set the event type to AppWindowResizeEvent.

            /**
             * \brief Get the new width of the application window.
             * 
             * \return The new width of the application window.
             */
            UInt32 GetWidth() const { return m_Width; }

            /**
             * \brief Get the new height of the application window.
             * 
             * \return The new height of the application window.
             */
            UInt32 GetHeight() const { return m_Height; }

        private:
            UInt32 m_Width{0}; ///< The new width of the application window.
            UInt32 m_Height{0}; ///< The new height of the application window.
    };

    /**
     * \brief Event class for window frame resize events.
     * 
     * This class represents an event that occurs when the frame of the application window is being resized.
     */
    class AppWindowFrameResizeEvent : public Event
    {
        public:
            /**
             * \brief Constructor for AppWindowFrameResizeEvent.
             * 
             * \param width The new width of the frame of the application window.
             * \param height The new height of the frame of the application window.
             */
            AppWindowFrameResizeEvent(UInt32 width, UInt32 height) : m_Width(width), m_Height(height) {}

            /**
             * \brief Virtual destructor for AppWindowFrameResizeEvent.
             */
            virtual ~AppWindowFrameResizeEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application); ///< Set the event category to Application.
            EVENT_CLASS_TYPE(EventType::AppWindowFrameResizeEvent); ///< Set the event type to AppWindowFrameResizeEvent.

            /**
             * \brief Get the new width of the frame of the application window.
             * 
             * \return The new width of the frame of the application window.
             */
            UInt32 GetWidth() const { return m_Width; }

            /**
             * \brief Get the new height of the frame of the application window.
             * 
             * \return The new height of the frame of the application window.
             */
            UInt32 GetHeight() const { return m_Height; }

        private:
            UInt32 m_Width{0}; ///< The new width of the frame of the application window.
            UInt32 m_Height{0}; ///< The new height of the frame of the application window.
    };

    /**
     * @brief Event that is fired when the position of the application window changes.
     * 
     * This event is triggered when the position of the application window is updated.
     * It contains the new x and y coordinates of the window position.
     */
    class AppWindowPosChangeEvent : public Event
    {
        public:
            /**
             * @brief Constructor for AppWindowPosChangeEvent.
             * 
             * @param x The new x-coordinate of the application window.
             * @param y The new y-coordinate of the application window.
             */
            AppWindowPosChangeEvent(UInt32 x, UInt32 y) : m_X(x), m_Y(y) {}

            /**
             * @brief Virtual destructor for AppWindowPosChangeEvent.
             */
            virtual ~AppWindowPosChangeEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application); ///< Set the event category to Application.
            EVENT_CLASS_TYPE(EventType::AppWindowPosChangeEvent); ///< Set the event type to AppWindowPosChangeEvent.

            /**
             * @brief Get the new x-coordinate of the application window.
             * 
             * @return The new x-coordinate of the application window.
             */
            UInt32 GetX() const { return m_X; }

            /**
             * @brief Get the new y-coordinate of the application window.
             * 
             * @return The new y-coordinate of the application window.
             */
            UInt32 GetY() const { return m_Y; }

        private:
            UInt32 m_X{0}; ///< The new x-coordinate of the application window.
            UInt32 m_Y{0}; ///< The new y-coordinate of the application window.
    };

    /**
     * @brief Event that is fired when the application window gains focus.
     * 
     * This event is fired when the application window gains focus. It is used to
     * notify the application that the window has gained focus.
     */
    class AppWindowFocusGainEvent : public Event
    {
        public:
            /**
             * @brief Constructor for AppWindowFocusGainEvent.
             * 
             * This constructor is used to create an AppWindowFocusGainEvent.
             */
            AppWindowFocusGainEvent() = default;

            /**
             * @brief Virtual destructor for AppWindowFocusGainEvent.
             * 
             * This destructor is used to destroy an AppWindowFocusGainEvent.
             */
            virtual ~AppWindowFocusGainEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application); ///< Set the event category to Application.
            EVENT_CLASS_TYPE(EventType::AppWindowFocusGainEvent); ///< Set the event type to AppWindowFocusGainEvent.
    };

    /**
     * @brief Event that is fired when the application window loses focus.
     * 
     * This event is fired when the application window loses focus. It is used to
     * notify the application that the window has lost focus.
     */
    class AppWindowFocusLostEvent : public Event
    {
        public:
            /**
             * @brief Constructor for AppWindowFocusLostEvent.
             * 
             * This constructor is used to create an AppWindowFocusLostEvent.
             */
            AppWindowFocusLostEvent() = default;

            /**
             * @brief Virtual destructor for AppWindowFocusLostEvent.
             * 
             * This destructor is used to destroy an AppWindowFocusLostEvent.
             */
            virtual ~AppWindowFocusLostEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application); ///< Set the event category to Application.
            EVENT_CLASS_TYPE(EventType::AppWindowFocusLostEvent); ///< Set the event type to AppWindowFocusLostEvent.
    };

    /**
     * @brief Event that is fired when the application window is minimized.
     * 
     * This event is fired when the application window is minimized. It is used to
     * notify the application that the window has been minimized.
     */
    class AppWindowMinimizeEvent : public Event
    {
        public:
            /**
             * @brief Constructor for AppWindowMinimizeEvent.
             * 
             * This constructor is used to create an AppWindowMinimizeEvent.
             */
            AppWindowMinimizeEvent() = default;

            /**
             * @brief Virtual destructor for AppWindowMinimizeEvent.
             * 
             * This destructor is used to destroy an AppWindowMinimizeEvent.
             */
            virtual ~AppWindowMinimizeEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application); ///< Set the event category to Application.
            EVENT_CLASS_TYPE(EventType::AppWindowMinimizedEvent); ///< Set the event type to AppWindowMinimizedEvent.
    };

    /**
     * @brief Event that is fired when the application window is maximized.
     * 
     * This event is fired when the application window is maximized. It is used to
     * notify the application that the window has been maximized.
     */
    class AppWindowMaximizeEvent : public Event
    {
        public:
            /**
             * @brief Constructor for AppWindowMaximizeEvent.
             * 
             * This constructor is used to create an AppWindowMaximizeEvent.
             */
            AppWindowMaximizeEvent() = default;

            /**
             * @brief Virtual destructor for AppWindowMaximizeEvent.
             * 
             * This destructor is used to destroy an AppWindowMaximizeEvent.
             */
            virtual ~AppWindowMaximizeEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application); ///< Set the event category to Application.
            EVENT_CLASS_TYPE(EventType::AppWindowMaximizedEvent); ///< Set the event type to AppWindowMaximizedEvent.
    };
}