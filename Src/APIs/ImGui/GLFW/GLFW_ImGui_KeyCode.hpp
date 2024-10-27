#pragma once

#include <GLFW/glfw3.h>
#include <imgui/imgui.h>

namespace TE::APIs::ImGui::Impl_GLFW
{
    inline ImGuiKey GetImGuiKeyCode(int glfwKeyCode);
}