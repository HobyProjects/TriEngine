#pragma once

#include "InputHandler.hpp"

namespace TE::APIs::GLFW
{
    /**
     * @class GLFW_InputHandler
     *
     * @brief A class that acts as an input handler for GLFW windows.
     *
     * This class is used to handle input events in GLFW windows. It
     * provides functions to target a window, check if a key is pressed, and
     * check if a mouse button is pressed.
     */
    class GLFW_InputHandler : public TE::Events::InputHandler
    {
        public:
            /**
             * @brief Default constructor for GLFW_InputHandler.
             *
             * This constructor is used to initialize the GLFW_InputHandler class.
             */
            GLFW_InputHandler() = default;

            /**
             * @brief Virtual destructor for GLFW_InputHandler.
             *
             * This destructor is used to destroy a GLFW_InputHandler object.
             */
            virtual ~GLFW_InputHandler() = default;

            /**
             * @brief Targets a window for input events.
             *
             * This function is used to target a window for input events. It
             * takes a shared pointer to a TE::Core::Window object as a
             * parameter.
             *
             * @param window A shared pointer to a TE::Core::Window object.
             */
            virtual void TargetWindow(const std::shared_ptr<TE::Core::Window>& window) override;

            /**
             * @brief Checks if a key is pressed.
             *
             * This function is used to check if a key is pressed. It takes a
             * TE::Core::KeyCodes value as a parameter.
             *
             * @param keyCode The TE::Core::KeyCodes value to check.
             */
            virtual bool IsKeyPressed(TE::Core::KeyCodes keyCode) override;

            /**
             * @brief Checks if a mouse button is pressed.
             *
             * This function is used to check if a mouse button is pressed. It
             * takes a TE::Core::MouseButton value as a parameter.
             *
             * @param mouseButton The TE::Core::MouseButton value to check.
             */
            virtual bool IsMouseButtonPressed(TE::Core::MouseButton mouseButton) override;
    };
}