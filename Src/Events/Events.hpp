#pragma once

#include <string>
#include <functional>
#include <type_traits>

#include "Base.hpp"
#include "Logs.hpp"

namespace TE::Events
{
    /**
     * @brief Event categories
     * 
     * Categories can be used to group events together and filter them more easily.
     */
    enum class EventCategory
    {
        Application = 0,    ///< Events related to the application.
        Keyboard    = 1,    ///< Events related to the keyboard.
        Mouse       = 2,    ///< Events related to the mouse.
        Unknown     = 3,    ///< Unknown event category.
    };

    /**
     * @brief Enumeration for different types of events.
     * 
     * This enumeration defines all possible event types that can be handled
     * within the application. Events are represented as bit flags for efficient
     * filtering and categorization.
     */
    enum class EventType
    {
        AppWindowResizeEvent        = TE_BIT(0),  ///< Event for window resizing.
        AppWindowCloseEvent         = TE_BIT(1),  ///< Event for window closing.
        AppWindowPosChangeEvent     = TE_BIT(2),  ///< Event for window position change.
        AppWindowMaximizedEvent     = TE_BIT(3),  ///< Event for window being maximized.
        AppWindowMinimizedEvent     = TE_BIT(4),  ///< Event for window being minimized.
        AppWindowFocusGainEvent     = TE_BIT(5),  ///< Event for window focus gain.
        AppWindowFocusLostEvent     = TE_BIT(6),  ///< Event for window focus loss.
        AppWindowFrameResizeEvent   = TE_BIT(7),  ///< Event for window frame resize.

        KeyboardKeyPressEvent       = TE_BIT(8),  ///< Event for keyboard key press.
        KeyboardKeyReleaseEvent     = TE_BIT(9),  ///< Event for keyboard key release.
        KeyboardKeyRepeatEvent      = TE_BIT(10), ///< Event for keyboard key repeat.
        KeyboardKeyCharEvent        = TE_BIT(11), ///< Event for keyboard character input.

        MouseButtonPressEvent       = TE_BIT(12), ///< Event for mouse button press.
        MouseButtonReleaseEvent     = TE_BIT(13), ///< Event for mouse button release.
        MouseWheelEvent             = TE_BIT(14), ///< Event for mouse wheel scrolling.
        MouseCursorPosChangeEvent   = TE_BIT(15), ///< Event for mouse cursor position change.
        MouseCursorEnterEvent       = TE_BIT(16), ///< Event for mouse cursor entering window.
        MouseCursorLeaveEvent       = TE_BIT(17), ///< Event for mouse cursor leaving window.
    };

    /**
     * @brief Macro to define the type of an event class.
     * 
     * This macro should be used within the definition of an event class to
     * define the type of the event. The type of the event is used to identify
     * the event and to filter events.
     * 
     * @param type The type of the event.
     */
    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return type; } \
						virtual EventType GetEventType() const override { return GetStaticType(); } \
						virtual const char* GetName() const override { return #type; }

	/**
	 * @brief Macro to define the category of an event class.
	 * 
	 * This macro should be used within the definition of an event class to
	 * define the category of the event. The category of the event is used to
	 * group events together and to filter events.
	 * 
	 * @param category The category of the event.
	 */
    #define EVENT_CLASS_CATEGORY(category) virtual EventCategory GetCategory() const override { return category; }

    /**
     * \brief The base class for all events.
     *
     * Events are used to notify the application about changes in the state of the
     * application or the window. Events are used to handle user input, such as
     * mouse and keyboard events, as well as to handle window events such as
     * resizing and closing.
     */
    class Event 
	{
		public:
			/**
			 * \brief Default constructor.
			 */
			Event() = default;

			/**
			 * \brief Virtual destructor.
			 */
			virtual ~Event() = default;

			/**
			 * \brief Gets the type of the event.
			 * \return The type of the event.
			 */
			virtual EventType GetEventType() const = 0;

			/**
			 * \brief Gets the category of the event.
			 * \return The category of the event.
			 */
			virtual EventCategory GetCategory() const = 0;

			/**
			 * \brief Gets the name of the event as a string.
			 * \return The name of the event as a string.
			 */
			virtual const char* GetName() const = 0;

			/**
			 * \brief Converts the event to a string representation.
			 * \return The string representation of the event.
			 */
			virtual std::string ToString() const { return std::string(GetName()); }

			/**
			 * \brief Checks if the category of the event is equal to the given category.
			 * \param category The category to compare with.
			 * \return True if the categories are equal, false otherwise.
			 */
			bool CategoryEquals(EventCategory category) const 
			{
				return GetCategory() == category;
			}

		public:
			/**
			 * \brief A flag indicating if the event has been handled.
			 * When an event is handled, this flag should be set to true.
			 */
			bool Handled{ false };
	};

    /**
     * \brief Class for handling events.
     * This class is used to handle events in the application. It provides a simple
     * way to dispatch events to the appropriate handlers.
     */
    class EventHandler 
    {
    public:
        /**
         * \brief Constructor.
         * \param event The event to handle.
         */
        EventHandler(Event& event) : 
            m_Event(event) {}

        /**
         * \brief Dispatches an event to a handler.
         * \param T The type of the event to dispatch.
         * \param function The function to call to handle the event.
         * \return True if the event was handled, false otherwise.
         */
        template<typename T, typename Function>
        bool Dispatch(const Function& function) 
        {
            if (m_Event.GetEventType() == T::GetStaticType()) 
            {
                m_Event.Handled |= function(static_cast<T&>(m_Event));
                return true;
            }
            
            return false;
        }

    private:
        Event& m_Event;
    };

    /// \brief A callback function for handling events.
    /// A callback function for handling events. The function takes a single
    /// argument of type Event& which is the event to be handled.
    using EventCallback = std::function<void(Event&)>;
}

/// \brief Macro to create a lambda function for event callbacks.
///
/// This macro generates a lambda function that captures the current object (`this`)
/// and forwards all arguments to the specified member function.
///
/// \param fn The member function to be invoked by the lambda.
#define TRIMANA_EVENT_CALLBACK(fn) \
    [this](auto&&... args) -> decltype(auto) { \
        return this->fn(std::forward<decltype(args)>(args)...); \
    }

