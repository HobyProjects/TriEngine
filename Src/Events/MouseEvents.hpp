#pragma once

#include "Events.hpp"
#include "TypeDef.hpp"

namespace TE::Events
{
    class MouseButtonPressEvent : public Event
    {
        public:
            MouseButtonPressEvent(TE::Core::MouseButton button) : m_Button(button) {}
            virtual ~MouseButtonPressEvent() = default;

            UInt32 GetMouseButton() const
            {
                return m_Button;
            }

            EVENT_CLASS_CATEGORY(EventCategory::Mouse);
            EVENT_CLASS_TYPE(EventType::MouseButtonPressEvent)

        private:
            TE::Core::MouseButton m_Button;
    };

    class MouseButtonReleaseEvent : public Event
    {
        public:
            MouseButtonReleaseEvent(TE::Core::MouseButton button) : m_Button(button) {}
            virtual ~MouseButtonReleaseEvent() = default;

            TE::Core::MouseButton GetMouseButton() const
            {
                return m_Button;
            }

            EVENT_CLASS_CATEGORY(EventCategory::Mouse)           
            EVENT_CLASS_TYPE(EventType::MouseButtonReleaseEvent)

        private:
            TE::Core::MouseButton m_Button; 
    };

    class MouseCursorPosChangeEvent : public Event
    {
        public:
            MouseCursorPosChangeEvent(Float64 posX, Float64 posY) : m_PosX(posX), m_PosY(posY) {}
            virtual ~MouseCursorPosChangeEvent() = default;

            Float64 GetMousePosX() const { return m_PosX; }
            Float64 GetMousePosY() const { return m_PosY; }

            EVENT_CLASS_CATEGORY(EventCategory::Mouse);
            EVENT_CLASS_TYPE(EventType::MouseCursorPosChangeEvent)

        private:
            Float64 m_PosX;
            Float64 m_PosY;
    };

    class MouseScrollEvent : public Event
    {
        public:
            MouseScrollEvent(Float64 offsetX, Float64 offsetY) : m_OffsetX(offsetX), m_OffsetY(offsetY) {}
            virtual ~MouseScrollEvent() = default;

            Float64 GetMouseScrollOffsetX() const { return m_OffsetX; }
            Float64 GetMouseScrollOffsetY() const { return m_OffsetY; }

            EVENT_CLASS_CATEGORY(EventCategory::Mouse);
            EVENT_CLASS_TYPE(EventType::MouseWheelEvent);

        private:
            Float64 m_OffsetX;
            Float64 m_OffsetY;
    };

    class MouseCursorEnterEvent : public Event
    {
        public:
            MouseCursorEnterEvent() = default;
            virtual ~MouseCursorEnterEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Mouse);
            EVENT_CLASS_TYPE(EventType::MouseCursorEnterEvent);
    };

    class MouseCursorLeaveEvent : public Event
    {
        public:
            MouseCursorLeaveEvent() = default;
            virtual ~MouseCursorLeaveEvent() = default;

            EVENT_CLASS_CATEGORY(EventCategory::Mouse);
            EVENT_CLASS_TYPE(EventType::MouseCursorLeaveEvent);
    };
}