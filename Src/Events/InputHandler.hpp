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

            virtual void TargetWindow(const Ref<TE::Core::IWindow>& window) = TE_NULL;
            virtual Boolean IsKeyPressed(TE::Core::KeyCodes keyCode) = TE_NULL;
            virtual Boolean IsMouseButtonPressed(TE::Core::MouseButton button) = TE_NULL;
            virtual Vec2 GetMousePosition() = TE_NULL;
    };
    
    Ref<TE::Events::IInputHandler> CreateInputHandler(TE::Core::ServiceAPI api = TE::Core::ServiceAPI::API_GLFW);
}