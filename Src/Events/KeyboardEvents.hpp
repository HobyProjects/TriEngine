#pragma once

#include "Events.hpp"
#include "KeyCodes.hpp"
#include "TypeDef.hpp"

namespace TE::Events
{
    /**
     * \brief Keyboard key press event class.
     * 
     * This class is used to handle keyboard key press events. It provides a way
     * to dispatch the event to the appropriate handlers.
     */
    class KeyboardKeyPressEvent : public Event
    {
        public:
            /**
             * Constructor.
             * \param keyCode The key code of the key that was pressed.
             */
            KeyboardKeyPressEvent(TE::Core::KeyCodes keyCode) : m_KeyCode(keyCode) {}
            virtual ~KeyboardKeyPressEvent() = default;

            /**
             * \brief Get the key code of the key that was pressed.
             * \return The key code of the key that was pressed.
             */
            TE::Core::KeyCodes GetKeyCode() const
            {
                return m_KeyCode;
            }

            /**
             * \brief Get the event category of the event.
             * \return The event category of the event.
             */
            EVENT_CLASS_CATEGORY(EventCategory::Keyboard);

            /**
             * \brief Get the event type of the event.
             * \return The event type of the event.
             */
            EVENT_CLASS_TYPE(EventType::KeyboardKeyPressEvent);

        private:
            /**
             * \brief The key code of the key that was pressed.
             */
            TE::Core::KeyCodes m_KeyCode;
    };






    /**
     * \brief Event that is dispatched when a key is released.
     *
     * This event is used to notify the application about a key release event.
     * The application can use this event to dispatch the event to the appropriate
     * handlers.
     */
    class KeyboardKeyReleaseEvent : public Event
    {
        public:
            /**
             * \brief Constructor.
             * \param keyCode The key code of the key that was released.
             */
            KeyboardKeyReleaseEvent(TE::Core::KeyCodes keyCode) : m_KeyCode(keyCode) {}
            virtual ~KeyboardKeyReleaseEvent() = default;

            /**
             * \brief Get the key code of the key that was released.
             * \return The key code of the key that was released.
             */
            TE::Core::KeyCodes GetKeyCode() const
            {
                return m_KeyCode;
            }

            /**
             * \brief Get the event category of the event.
             * \return The event category of the event.
             */
            EVENT_CLASS_CATEGORY(EventCategory::Keyboard);

            /**
             * \brief Get the event type of the event.
             * \return The event type of the event.
             */
            EVENT_CLASS_TYPE(EventType::KeyboardKeyReleaseEvent);


        private:
            /**
             * \brief The key code of the key that was released.
             */
            TE::Core::KeyCodes m_KeyCode;
    };





    /**
     * \brief Event that is dispatched when a key is repeated.
     *
     * This event is used to notify the application about a key repeat event.
     * The application can use this event to dispatch the event to the appropriate
     * handlers.
     */
    class KeyboardKeyRepeatEvent : public Event
    {
        public:
            /**
             * \brief Constructor.
             * \param keyCode The key code of the key that was repeated.
             */
            KeyboardKeyRepeatEvent(TE::Core::KeyCodes keyCode) : m_KeyCode(keyCode) {}
            virtual ~KeyboardKeyRepeatEvent() = default;

            /**
             * \brief Get the key code of the key that was repeated.
             * \return The key code of the key that was repeated.
             */
            TE::Core::KeyCodes GetKeyCode() const
            {
                return m_KeyCode;
            }

            /**
             * \brief Get the event category of the event.
             * \return The event category of the event.
             */
            EVENT_CLASS_CATEGORY(EventCategory::Keyboard);

            /**
             * \brief Get the event type of the event.
             * \return The event type of the event.
             */
            EVENT_CLASS_TYPE(EventType::KeyboardKeyRepeatEvent);


        private:
            /**
             * \brief The key code of the key that was repeated.
             */ 
            TE::Core::KeyCodes m_KeyCode;
    };





    /**
     * \brief Event that is dispatched when a key character is entered.
     *
     * This event is used to notify the application about a key character
     * event. The application can use this event to dispatch the event to
     * the appropriate handlers.
     */
    class KeyboardKeyCharEvent : public Event
    {
        public:
            /**
             * \brief Constructor.
             * \param keyCode The key code of the key that was entered.
             */
            KeyboardKeyCharEvent(uint32_t keyCode) : m_KeyCode(keyCode) {}
            virtual ~KeyboardKeyCharEvent() = default;

            /**
             * \brief Get the key code of the key that was entered.
             * \return The key code of the key that was entered.
             */
            uint32_t GetKeyCode() const
            {
                return m_KeyCode;
            }

            /**
             * \brief Get the event category of the event.
             * \return The event category of the event.
             */
            EVENT_CLASS_CATEGORY(EventCategory::Keyboard);

            /**
             * \brief Get the event type of the event.
             * \return The event type of the event.
             */
            EVENT_CLASS_TYPE(EventType::KeyboardKeyCharEvent);

        private:
            /**
             * \brief The key code of the key that was entered.
             */
            uint32_t m_KeyCode;
    };
}