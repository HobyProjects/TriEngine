#pragma once

#include "Window.hpp"
#include "KeyCodes.hpp"

namespace TE::Events
{
    class IInputHandler
    {
        public:
            IInputHandler() = default;
            virtual ~IInputHandler() = default;

            virtual void TargetWindow(const Ref<TE::Core::Window>& window) = TE_NULL;
            virtual Boolean IsKeyPressed(TE::Core::KeyCodes keyCode) = TE_NULL;
            virtual Boolean IsMouseButtonPressed(TE::Core::MouseButton button) = TE_NULL;
            virtual Vec2 GetMousePosition() = TE_NULL;
    };
    
    Ref<TE::Events::IInputHandler> CreateInputHandler(TE::Core::ServiceAPIs api = TE::Core::ServiceAPIs::API_GLFW);
}