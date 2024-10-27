#pragma once

#include <string>
#include <functional>
#include <type_traits>

#include "TypeDef.hpp"
#include "Base.hpp"
#include "Logs.hpp"

namespace TE::Events
{
    enum class EventCategory
    {
        Application = 0,    
        Keyboard    = 1,    
        Mouse       = 2,    
        Unknown     = 3,    
    };

    enum class EventType
    {
        AppWindowResizeEvent        = TE_BIT(0),  
        AppWindowCloseEvent         = TE_BIT(1),  
        AppWindowPosChangeEvent     = TE_BIT(2),  
        AppWindowMaximizedEvent     = TE_BIT(3),  
        AppWindowMinimizedEvent     = TE_BIT(4),  
        AppWindowFocusGainEvent     = TE_BIT(5),  
        AppWindowFocusLostEvent     = TE_BIT(6),  
        AppWindowFrameResizeEvent   = TE_BIT(7),  

        KeyboardKeyPressEvent       = TE_BIT(8),  
        KeyboardKeyReleaseEvent     = TE_BIT(9),  
        KeyboardKeyRepeatEvent      = TE_BIT(10), 
        KeyboardKeyCharEvent        = TE_BIT(11), 

        MouseButtonPressEvent       = TE_BIT(12), 
        MouseButtonReleaseEvent     = TE_BIT(13), 
        MouseWheelEvent             = TE_BIT(14), 
        MouseCursorPosChangeEvent   = TE_BIT(15), 
        MouseCursorEnterEvent       = TE_BIT(16), 
        MouseCursorLeaveEvent       = TE_BIT(17), 
    };

    #define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return type; } \
						virtual EventType GetEventType() const override { return GetStaticType(); } \
						virtual CString GetName() const override { return #type; }

    #define EVENT_CLASS_CATEGORY(category) virtual EventCategory GetCategory() const override { return category; }

    class Event 
	{
		public:
			Event() = default;
			virtual ~Event() = default;

			virtual EventType GetEventType() const = TE_NULL;
			virtual EventCategory GetCategory() const = TE_NULL;
			virtual CString GetName() const = TE_NULL;
			virtual String ToString() const { return String(GetName()); }
			Boolean CategoryEquals(EventCategory category) const 
			{
				return GetCategory() == category;
			}

		public:
			Boolean Handled{ TE_FALSE };
	};

    class EventHandler 
    {
        public:
            EventHandler(Event& event) : m_Event(event) {}
            ~EventHandler() = default;

            template<typename T, typename Function>
            Boolean Dispatch(const Function& function) 
            {
                if (m_Event.GetEventType() == T::GetStaticType()) 
                {
                    m_Event.Handled |= function(static_cast<T&>(m_Event));
                    return TR_TRUE;
                }
                
                return TE_FALSE;
            }

        private:
            Event& m_Event;
    };

    using EventCallback = std::function<void(Event&)>;
}

#define TRIMANA_EVENT_CALLBACK(fn) \
    [this](auto&&... args) -> decltype(auto) { \
        return this->fn(std::forward<decltype(args)>(args)...); \
    }

