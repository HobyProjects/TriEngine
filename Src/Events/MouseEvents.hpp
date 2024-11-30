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
            MouseCursorPosChangeEvent(Double posX, Double posY) : m_PosX(posX), m_PosY(posY) {}
            virtual ~MouseCursorPosChangeEvent() = default;

            Double GetMousePosX() const { return m_PosX; }
            Double GetMousePosY() const { return m_PosY; }

            EVENT_CLASS_CATEGORY(EventCategory::Mouse);
            EVENT_CLASS_TYPE(EventType::MouseCursorPosChangeEvent)

        private:
            Double m_PosX;
            Double m_PosY;
    };

    class MouseScrollEvent : public Event
    {
        public:
            MouseScrollEvent(Double offsetX, Double offsetY) : m_OffsetX(offsetX), m_OffsetY(offsetY) {}
            virtual ~MouseScrollEvent() = default;

            Double GetMouseScrollOffsetX() const { return m_OffsetX; }
            Double GetMouseScrollOffsetY() const { return m_OffsetY; }

            EVENT_CLASS_CATEGORY(EventCategory::Mouse);
            EVENT_CLASS_TYPE(EventType::MouseWheelEvent);

        private:
            Double m_OffsetX;
            Double m_OffsetY;
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