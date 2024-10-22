#pragma once

#include <GLFW/glfw3.h>
#include <imgui/imgui.h>

namespace TE::APIs::ImGui::Impl_GLFW
{
    /**
     * @brief Converts a GLFW key code to an ImGui key code.
     *
     * This function takes a GLFW key code as input and returns the corresponding
     * ImGui key code. It supports a variety of key codes including standard
     * keys, arrow keys, and function keys.
     *
     * @param glfwKeyCode The GLFW key code to convert.
     * @return The corresponding ImGui key code.
     */
    inline ImGuiKey GetImGuiKeyCode(int glfwKeyCode);
}