#pragma once

#include "InputHandler.hpp"

namespace TE::APIs::GLFW
{
    class GLFWAPI_InputHandler : public TE::Events::InputHandler
    {
        public:
            GLFWAPI_InputHandler() = default;
            virtual ~GLFWAPI_InputHandler() = default;

            virtual void TargetWindow(const Ref<TE::Core::Window>& window) override;
            virtual Boolean IsKeyPressed(TE::Core::KeyCodes keyCode) override;
            virtual Boolean IsMouseButtonPressed(TE::Core::MouseButton mouseButton) override;
            virtual Vec2 GetMousePosition() override;
    };
}