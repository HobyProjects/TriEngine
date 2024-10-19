#pragma once

#include "Events.hpp"
#include "TypeDef.hpp"

namespace TE::Events
{
    /**
     * @brief Event that is fired when a mouse button is pressed.
     *
     * This event is fired when a mouse button is pressed. The event contains the
     * mouse button that was pressed.
     */
    class MouseButtonPressEvent : public Event
    {
        public:
            /**
             * @brief Constructor.
             * @param[in] button The button that was pressed.
             */
            MouseButtonPressEvent(UInt32 button) : m_Button(button) {}

            /**
             * @brief Destructor.
             */
            virtual ~MouseButtonPressEvent() = default;

            /**
             * @brief Gets the button that was pressed.
             * @return The button that was pressed.
             */
            UInt32 GetMouseButton() const
            {
                return m_Button;
            }

            /**
             * @brief Gets the category of the event.
             * @return The category of the event.
             */
            EVENT_CLASS_CATEGORY(EventCategory::Mouse)

            /**
             * @brief Gets the type of the event.
             * @return The type of the event.
             */
            EVENT_CLASS_TYPE(EventType::MouseButtonPressEvent)

        private:
            /**
             * @brief The button that was pressed.
             */
            UInt32 m_Button;
    };



    /**
     * @brief Event that is fired when a mouse button is released.
     *
     * This event is fired when a mouse button is released. The event contains the
     * mouse button that was released.
     */
    class MouseButtonReleaseEvent : public Event
    {
        public:
            /**
             * @brief Constructor.
             * @param[in] button The button that was released.
             */
            MouseButtonReleaseEvent(UInt32 button) : m_Button(button) {}
            virtual ~MouseButtonReleaseEvent() = default;

            /**
             * @brief Gets the button that was released.
             * @return The button that was released.
             */
            UInt32 GetMouseButton() const
            {
                return m_Button;
            }

            /**
             * @brief Gets the category of the event.
             * @return The category of the event.
             */
            EVENT_CLASS_CATEGORY(EventCategory::Mouse)           

            /**
             * @brief Gets the type of the event.
             * @return The type of the event.
             */
            EVENT_CLASS_TYPE(EventType::MouseButtonReleaseEvent)

        private:
            /**
             * @brief The button that was released.
             */
            uint32_t m_Button; 
    };


    /**
     * @brief Event that is fired when the mouse cursor position changes.
     *
     * This event is fired when the mouse cursor moves. The event contains the
     * new position of the mouse cursor.
     */
    class MouseCursorPosChangeEvent : public Event
    {
        public:
            /**
             * @brief Constructor.
             * @param[in] posX The new position of the mouse cursor on the x-axis.
             * @param[in] posY The new position of the mouse cursor on the y-axis.
             */
            MouseCursorPosChangeEvent(Float64 posX, Float64 posY) : m_PosX(posX), m_PosY(posY) {}

            /**
             * @brief Destructor.
             */
            virtual ~MouseCursorPosChangeEvent() = default;

            /**
             * @brief Gets the new position of the mouse cursor on the x-axis.
             * @return The new position of the mouse cursor on the x-axis.
             */
            Float64 GetMousePosX() const { return m_PosX; }

            /**
             * @brief Gets the new position of the mouse cursor on the y-axis.
             * @return The new position of the mouse cursor on the y-axis.
             */
            Float64 GetMousePosY() const { return m_PosY; }

            /**
             * @brief Gets the category of the event.
             * @return The category of the event.
             */
            EVENT_CLASS_CATEGORY(EventCategory::Mouse);

            /**
             * @brief Gets the type of the event.
             * @return The type of the event.
             */
            EVENT_CLASS_TYPE(EventType::MouseCursorPosChangeEvent)

        private:
            /**
             * @brief The new position of the mouse cursor on the x-axis.
             */
            Float64 m_PosX;

            /**
             * @brief The new position of the mouse cursor on the y-axis.
             */
            Float64 m_PosY;
    };

    /**
     * @brief Event that is fired when the mouse scroll wheel is used.
     *
     * This event is fired when the mouse scroll wheel is used. The event contains the
     * offset values of the scroll wheel on the X and Y axes.
     */
    class MouseScrollEvent : public Event
    {
        public:
            /**
             * @brief Constructor.
             * @param[in] offsetX The offset of the scroll wheel on the X-axis.
             * @param[in] offsetY The offset of the scroll wheel on the Y-axis.
             */
            MouseScrollEvent(Float64 offsetX, Float64 offsetY) : m_OffsetX(offsetX), m_OffsetY(offsetY) {}

            /**
             * @brief Destructor.
             */
            virtual ~MouseScrollEvent() = default;

            /**
             * @brief Gets the offset of the scroll wheel on the X-axis.
             * @return The offset of the scroll wheel on the X-axis.
             */
            Float64 GetMouseScrollOffsetX() const { return m_OffsetX; }

            /**
             * @brief Gets the offset of the scroll wheel on the Y-axis.
             * @return The offset of the scroll wheel on the Y-axis.
             */
            Float64 GetMouseScrollOffsetY() const { return m_OffsetY; }

            /**
             * @brief Gets the category of the event.
             * @return The category of the event.
             */
            EVENT_CLASS_CATEGORY(EventCategory::Mouse);

            /**
             * @brief Gets the type of the event.
             * @return The type of the event.
             */
            EVENT_CLASS_TYPE(EventType::MouseWheelEvent);

        private:
            Float64 m_OffsetX; /**< The offset of the scroll wheel on the X-axis. */
            Float64 m_OffsetY; /**< The offset of the scroll wheel on the Y-axis. */
    };

    /**
     * @brief Event that is fired when the mouse cursor enters a window.
     *
     * This event is fired when the mouse cursor enters a window.
     */
    class MouseCursorEnterEvent : public Event
    {
        public:
            /**
             * @brief Default constructor for MouseCursorEnterEvent.
             */
            MouseCursorEnterEvent() = default;

            /**
             * @brief Virtual destructor for MouseCursorEnterEvent.
             */
            virtual ~MouseCursorEnterEvent() = default;

            /**
             * @brief Gets the category of the MouseCursorEnterEvent.
             * @return The category of the MouseCursorEnterEvent.
             */
            EVENT_CLASS_CATEGORY(EventCategory::Mouse);

            /**
             * @brief Gets the type of the MouseCursorEnterEvent.
             * @return The type of the MouseCursorEnterEvent.
             */
            EVENT_CLASS_TYPE(EventType::MouseCursorEnterEvent);
    };

    /**
     * @brief Event that is fired when the mouse cursor leaves a window.
     *
     * This event is fired when the mouse cursor leaves a window.
     */
    class MouseCursorLeaveEvent : public Event
    {
        public:
            /**
             * @brief Default constructor for MouseCursorLeaveEvent.
             */
            MouseCursorLeaveEvent() = default;

            /**
             * @brief Virtual destructor for MouseCursorLeaveEvent.
             */
            virtual ~MouseCursorLeaveEvent() = default;

            /**
             * @brief Gets the category of the MouseCursorLeaveEvent.
             * @return The category of the MouseCursorLeaveEvent.
             */
            EVENT_CLASS_CATEGORY(EventCategory::Mouse);

            /**
             * @brief Gets the type of the MouseCursorLeaveEvent.
             * @return The type of the MouseCursorLeaveEvent.
             */
            EVENT_CLASS_TYPE(EventType::MouseCursorLeaveEvent);
    };
}