#include "GLFW_InputHandler.hpp"

namespace TE::APIs::GLFW
{
    static std::shared_ptr<TE::Core::Window> s_TargetWindow = nullptr;

    void GLFW_InputHandler::TargetWindow(const std::shared_ptr<TE::Core::Window>& window)
    {
        s_TargetWindow = window;
    }

    bool GLFW_InputHandler::IsKeyPressed(TE::Core::KeyCodes keyCode)
    {
        if(!s_TargetWindow)
        {
            TE_CORE_ERROR("Target window not set");
            return false;
        }

        auto state = glfwGetKey((GLFWwindow*)s_TargetWindow->GetNativeWindow(), static_cast<int>(keyCode));
        return state == TE::Core::KeyState::KEY_PRESSED || state == TE::Core::KeyState::KEY_REPEAT;
    }

    bool GLFW_InputHandler::IsMouseButtonPressed(TE::Core::MouseButton mouseButton)
    {
        if(!s_TargetWindow)
        {
            TE_CORE_ERROR("Target window not set");
            return false;
        }

        auto state = glfwGetMouseButton((GLFWwindow*)s_TargetWindow->GetNativeWindow(), static_cast<int>(mouseButton));
        return state == TE::Core::MouseButtonState::MOUSE_BUTTON_PRESSED;
    }



}