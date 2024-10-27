#pragma once

#include "Events.hpp"
#include "TypeDef.hpp"

namespace TE::Events
{
    class AppWindowCloseEvent : public Event
    {
        public:
            AppWindowCloseEvent() = default;
            virtual ~AppWindowCloseEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application); 
            EVENT_CLASS_TYPE(EventType::AppWindowCloseEvent);
    };

    class AppWindowResizeEvent : public Event
    {
        public:
            AppWindowResizeEvent(UInt32 width, UInt32 height) : m_Width(width), m_Height(height) {}
            virtual ~AppWindowResizeEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application);
            EVENT_CLASS_TYPE(EventType::AppWindowResizeEvent);

            UInt32 GetWidth() const { return m_Width; }
            UInt32 GetHeight() const { return m_Height; }

        private:
            UInt32 m_Width{TE_NULL};
            UInt32 m_Height{TE_NULL};
    };

    class AppWindowFrameResizeEvent : public Event
    {
        public:
            AppWindowFrameResizeEvent(UInt32 width, UInt32 height) : m_Width(width), m_Height(height) {}
            virtual ~AppWindowFrameResizeEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application);
            EVENT_CLASS_TYPE(EventType::AppWindowFrameResizeEvent);

            UInt32 GetWidth() const { return m_Width; }
            UInt32 GetHeight() const { return m_Height; }

        private:
            UInt32 m_Width{TE_NULL}; 
            UInt32 m_Height{TE_NULL};
    };

    class AppWindowPosChangeEvent : public Event
    {
        public:
            AppWindowPosChangeEvent(UInt32 x, UInt32 y) : m_X(x), m_Y(y) {}
            virtual ~AppWindowPosChangeEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application);
            EVENT_CLASS_TYPE(EventType::AppWindowPosChangeEvent);

            UInt32 GetX() const { return m_X; }
            UInt32 GetY() const { return m_Y; }

        private:
            UInt32 m_X{TE_NULL};
            UInt32 m_Y{TE_NULL};
    };

    class AppWindowFocusGainEvent : public Event
    {
        public:
            AppWindowFocusGainEvent() = default;
            virtual ~AppWindowFocusGainEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application);
            EVENT_CLASS_TYPE(EventType::AppWindowFocusGainEvent);
    };

    class AppWindowFocusLostEvent : public Event
    {
        public:
            AppWindowFocusLostEvent() = default;
            virtual ~AppWindowFocusLostEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application);
            EVENT_CLASS_TYPE(EventType::AppWindowFocusLostEvent);
    };

    class AppWindowMinimizeEvent : public Event
    {
        public:
            AppWindowMinimizeEvent() = default;
            virtual ~AppWindowMinimizeEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application);
            EVENT_CLASS_TYPE(EventType::AppWindowMinimizedEvent);
    };

    class AppWindowMaximizeEvent : public Event
    {
        public:
            AppWindowMaximizeEvent() = default;
            virtual ~AppWindowMaximizeEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Application); 
            EVENT_CLASS_TYPE(EventType::AppWindowMaximizedEvent);
    };
}