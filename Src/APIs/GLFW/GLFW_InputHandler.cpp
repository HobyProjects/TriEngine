#include "GLFW_InputHandler.hpp"

namespace TE::APIs::GLFW
{
    static Ref<TE::Core::IWindow> s_TargetWindow = nullptr;

    void GLFWAPI_InputHandler::TargetWindow(const Ref<TE::Core::IWindow>& window)
    {
        s_TargetWindow = window;
    }

    Boolean GLFWAPI_InputHandler::IsKeyPressed(TE::Core::KeyCodes keyCode)
    {
        if(!s_TargetWindow)
        {
            TE_CORE_ERROR("Target window not set");
            return TE_FALSE;
        }

        auto state = glfwGetKey((GLFWwindow*)s_TargetWindow->GetNativeWindow(), static_cast<int>(keyCode));
        return state == TE::Core::KeyState::KEY_PRESSED || state == TE::Core::KeyState::KEY_REPEAT;
    }

    Boolean GLFWAPI_InputHandler::IsMouseButtonPressed(TE::Core::MouseButton mouseButton)
    {
        if(!s_TargetWindow)
        {
            TE_CORE_ERROR("Target window not set");
            return TE_FALSE;
        }

        auto state = glfwGetMouseButton((GLFWwindow*)s_TargetWindow->GetNativeWindow(), static_cast<int>(mouseButton));
        return state == TE::Core::MouseButtonState::MOUSE_BUTTON_PRESSED;
    }

    Vec2 GLFWAPI_InputHandler::GetMousePosition()
    {
        if(!s_TargetWindow)
        {
            TE_CORE_ERROR("Target window not set");
            return {0, 0};
        }

        double x, y;
        glfwGetCursorPos((GLFWwindow*)s_TargetWindow->GetNativeWindow(), &x, &y);
        return {static_cast<Float>(x), static_cast<Float>(y)};
    }



}