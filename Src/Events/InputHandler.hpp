#pragma once

#include "Window.hpp"
#include "KeyCodes.hpp"

namespace TE::Events
{
    /**
     * @class InputHandler
     * 
     * @brief Abstract base class for handling input events.
     * 
     * This class provides an interface for handling input events, including 
     * keyboard and mouse inputs. It requires derived classes to implement 
     * methods for targeting a window and checking the state of keys and 
     * mouse buttons.
     */
    class InputHandler
    {
        public:
            /**
             * @brief Default constructor for InputHandler.
             */
            InputHandler() = default;

            /**
             * @brief Virtual destructor for InputHandler.
             */
            virtual ~InputHandler() = default;

            /**
             * @brief Set the target window for input events.
             * @param window A shared pointer to the Window object to target.
             */
            virtual void TargetWindow(const std::shared_ptr<TE::Core::Window>& window) = 0;

            /**
             * @brief Check if a specific key is pressed.
             * @param keyCode The KeyCodes value representing the key.
             */
            virtual void IsKeyPressed(TE::Core::KeyCodes keyCode) = 0;

            /**
             * @brief Check if a specific mouse button is pressed.
             * @param button The MouseButton value representing the mouse button.
             */
            virtual void IsMouseButtonPressed(TE::Core::MouseButton button) = 0;
    };
}