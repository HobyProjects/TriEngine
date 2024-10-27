#pragma once

#include "Events.hpp"
#include "KeyCodes.hpp"
#include "TypeDef.hpp"

namespace TE::Events
{
    class KeyboardKeyPressEvent : public Event
    {
        public:
            KeyboardKeyPressEvent(TE::Core::KeyCodes keyCode) : m_KeyCode(keyCode) {}
            virtual ~KeyboardKeyPressEvent() = default;

            TE::Core::KeyCodes GetKeyCode() const
            {
                return m_KeyCode;
            }

            EVENT_CLASS_CATEGORY(EventCategory::Keyboard);
            EVENT_CLASS_TYPE(EventType::KeyboardKeyPressEvent);

        private:
            TE::Core::KeyCodes m_KeyCode;
    };

    class KeyboardKeyReleaseEvent : public Event
    {
        public:
            KeyboardKeyReleaseEvent(TE::Core::KeyCodes keyCode) : m_KeyCode(keyCode) {}
            virtual ~KeyboardKeyReleaseEvent() = default;

            TE::Core::KeyCodes GetKeyCode() const
            {
                return m_KeyCode;
            }

            EVENT_CLASS_CATEGORY(EventCategory::Keyboard);
            EVENT_CLASS_TYPE(EventType::KeyboardKeyReleaseEvent);


        private:
            TE::Core::KeyCodes m_KeyCode;
    };

    class KeyboardKeyRepeatEvent : public Event
    {
        public:
            KeyboardKeyRepeatEvent(TE::Core::KeyCodes keyCode) : m_KeyCode(keyCode) {}
            virtual ~KeyboardKeyRepeatEvent() = default;

            TE::Core::KeyCodes GetKeyCode() const
            {
                return m_KeyCode;
            }

            EVENT_CLASS_CATEGORY(EventCategory::Keyboard);
            EVENT_CLASS_TYPE(EventType::KeyboardKeyRepeatEvent);


        private:
            TE::Core::KeyCodes m_KeyCode;
    };

    class KeyboardKeyCharEvent : public Event
    {
        public:
            KeyboardKeyCharEvent(UInt32 keyCode) : m_KeyCode(keyCode) {}
            virtual ~KeyboardKeyCharEvent() = default;

            UInt32 GetKeyCode() const
            {
                return m_KeyCode;
            }

            EVENT_CLASS_CATEGORY(EventCategory::Keyboard);
            EVENT_CLASS_TYPE(EventType::KeyboardKeyCharEvent);

        private:
            UInt32 m_KeyCode;
    };
}