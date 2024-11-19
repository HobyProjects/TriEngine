#pragma once

#include "Window.hpp"
#include "KeyCodes.hpp"

namespace TE::Events
{
    class InputHandler
    {
        public:
            InputHandler() = default;
            virtual ~InputHandler() = default;

            virtual void TargetWindow(const Ref<TE::Core::Window>& window) = TE_NULL;
            virtual Boolean IsKeyPressed(TE::Core::KeyCodes keyCode) = TE_NULL;
            virtual Boolean IsMouseButtonPressed(TE::Core::MouseButton button) = TE_NULL;
            virtual Vec2 GetMousePosition() = TE_NULL;
    };
    
    Ref<TE::Events::InputHandler> CreateInputHandler(TE::Core::ServiceAPIs api = TE::Core::ServiceAPIs::API_GLFW);
}