#include "UI.hpp"
#include "Renderer.hpp"

namespace TE::UI
{
    UILayer::UILayer(std::shared_ptr<TE::Core::Window> window, TE::Core::WindowAPI windowApi, UITheme theme)
        : TE::Core::Layer("UILayer"), m_Window(window), m_Theme(theme), m_WindowApi(windowApi)
    {
    }

    void UILayer::OnAttach()
    {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGuiIO& io = ImGui::GetIO(); (void)io;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;       
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         
        io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable; 

        TRIMANA_ASSERT(m_Window != nullptr, "Window is null");
        (m_Theme == UITheme::Dark) ? SetDarkTheme() : SetLightTheme();

        UInt32 UI_init = (UInt32)(TE::Renderer::Renderer::GetAPI()) | (UInt32)(m_WindowApi);

        if(UI_init == (UInt32)TE::Renderer::RendererAPI::None | (UInt32)TE::Core::WindowAPI::None)
        {
            TRIMANA_ASSERT(false, "No rendering API selected");
            return;
        }

        if(UI_init == (UInt32)TE::Renderer::RendererAPI::OpenGL | (UInt32)TE::Core::WindowAPI::GLFW_API)
        {
            TE_CORE_INFO("Initializing ImGui for OpenGL");
            ImGui_ImplGlfw_InitForOpenGL((GLFWwindow*)m_Window->GetNativeWindow(), true);
            ImGui_ImplOpenGL3_Init("#version 430");
        }

        if(UI_init == (UInt32)TE::Renderer::RendererAPI::Vulkan | (UInt32)TE::Core::WindowAPI::GLFW_API)
        {
            TRIMANA_ASSERT(false, "Not implemented yet");
            return;
        }

        if(UI_init == (UInt32)TE::Renderer::RendererAPI::DirectX | (UInt32)TE::Core::WindowAPI::GLFW_API)
        {
            TRIMANA_ASSERT(false, "Not implemented yet");
            return;
        }

    }

    void UILayer::OnDetach()
    {
        UInt32 UI = (UInt32)(TE::Renderer::Renderer::GetAPI()) | (UInt32)(m_WindowApi);

        if(UI == (UInt32)TE::Renderer::RendererAPI::None | (UInt32)TE::Core::WindowAPI::None)
        {
            TRIMANA_ASSERT(false, "No rendering API selected");
            return;
        }

        if(UI == (UInt32)TE::Renderer::RendererAPI::OpenGL | (UInt32)TE::Core::WindowAPI::GLFW_API)
        {
            TE_CORE_INFO("Shutting down ImGui for OpenGL");
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplGlfw_Shutdown();
            ImGui::DestroyContext();
        }

        if(UI == (UInt32)TE::Renderer::RendererAPI::Vulkan | (UInt32)TE::Core::WindowAPI::GLFW_API)
        {
            TRIMANA_ASSERT(false, "Not implemented yet");
            return;
        }

        if(UI == (UInt32)TE::Renderer::RendererAPI::DirectX | (UInt32)TE::Core::WindowAPI::GLFW_API)
        {
            TRIMANA_ASSERT(false, "Not implemented yet");
            return;
        }
    }

    void UILayer::OnEvent(TE::Events::Event & events)
    {
        if(m_AllowEvents)
        {
            ImGuiIO& io = ImGui::GetIO();
            events.Handled |= events.CategoryEquals(TE::Events::EventCategory::Mouse) & io.WantCaptureMouse;
            events.Handled |= events.CategoryEquals(TE::Events::EventCategory::Keyboard) & io.WantCaptureKeyboard;
        }
    }

    void UILayer::Begin()
    {
        UInt32 UI = (UInt32)(TE::Renderer::Renderer::GetAPI()) | (UInt32)(m_WindowApi);

        if(UI == (UInt32)TE::Renderer::RendererAPI::None | (UInt32)TE::Core::WindowAPI::None)
        {
            TRIMANA_ASSERT(false, "No rendering API selected");
            return;
        }

        if(UI == (UInt32)TE::Renderer::RendererAPI::OpenGL | (UInt32)TE::Core::WindowAPI::GLFW_API)
        {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplGlfw_NewFrame();
            ImGui::NewFrame();
        }

        if(UI == (UInt32)TE::Renderer::RendererAPI::Vulkan | (UInt32)TE::Core::WindowAPI::GLFW_API)
        {
            TRIMANA_ASSERT(false, "Not implemented yet");
            return;
        }

        if(UI == (UInt32)TE::Renderer::RendererAPI::DirectX | (UInt32)TE::Core::WindowAPI::GLFW_API)
        {
            TRIMANA_ASSERT(false, "Not implemented yet");
            return;
        }

    }

    void UILayer::End()
    {
        ImGuiIO &io = ImGui::GetIO();
        io.DisplaySize = ImVec2(static_cast<float>(m_Window->GetWindowSpecification().Width), static_cast<float>(m_Window->GetWindowSpecification().Height));

        ImGui::EndFrame();
        ImGui::Render();
        UInt32 UI = (UInt32)(TE::Renderer::Renderer::GetAPI()) | (UInt32)(m_WindowApi);

        if(UI == (UInt32)TE::Renderer::RendererAPI::None | (UInt32)TE::Core::WindowAPI::None)
        {
            TRIMANA_ASSERT(false, "No rendering API selected");
            return;
        }

        if(UI == (UInt32)TE::Renderer::RendererAPI::OpenGL | (UInt32)TE::Core::WindowAPI::GLFW_API)
        {
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
            {
                GLFWwindow *backup_current_context = glfwGetCurrentContext();
                ImGui::UpdatePlatformWindows();
                ImGui::RenderPlatformWindowsDefault();
                glfwMakeContextCurrent(backup_current_context);
            } 
        }

        if(UI == (UInt32)TE::Renderer::RendererAPI::Vulkan | (UInt32)TE::Core::WindowAPI::GLFW_API)
        {
            TRIMANA_ASSERT(false, "Not implemented yet");
            return;
        }

        if(UI == (UInt32)TE::Renderer::RendererAPI::DirectX | (UInt32)TE::Core::WindowAPI::GLFW_API)
        {
            TRIMANA_ASSERT(false, "Not implemented yet");
            return;
        }
    }

    void UILayer::AllowEvents(bool allowEvents)
    {
        m_AllowEvents = allowEvents;
    }

    void UILayer::SetTheme(UITheme theme)
    {
        m_Theme = theme;
    }

    void UILayer::SetDarkTheme()
    {
        auto& colors = ImGui::GetStyle().Colors;
		colors[ImGuiCol_WindowBg] = ImVec4{ 0.1f, 0.105f, 0.11f, 1.0f };

		// Headers
		colors[ImGuiCol_Header] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
		colors[ImGuiCol_HeaderHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
		colors[ImGuiCol_HeaderActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		
		// Buttons
		colors[ImGuiCol_Button] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
		colors[ImGuiCol_ButtonHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
		colors[ImGuiCol_ButtonActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

		// Frame BG
		colors[ImGuiCol_FrameBg] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };
		colors[ImGuiCol_FrameBgHovered] = ImVec4{ 0.3f, 0.305f, 0.31f, 1.0f };
		colors[ImGuiCol_FrameBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };

		// Tabs
		colors[ImGuiCol_Tab] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		colors[ImGuiCol_TabHovered] = ImVec4{ 0.38f, 0.3805f, 0.381f, 1.0f };
		colors[ImGuiCol_TabActive] = ImVec4{ 0.28f, 0.2805f, 0.281f, 1.0f };
		colors[ImGuiCol_TabUnfocused] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		colors[ImGuiCol_TabUnfocusedActive] = ImVec4{ 0.2f, 0.205f, 0.21f, 1.0f };

		// Title
		colors[ImGuiCol_TitleBg] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		colors[ImGuiCol_TitleBgActive] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
		colors[ImGuiCol_TitleBgCollapsed] = ImVec4{ 0.15f, 0.1505f, 0.151f, 1.0f };
    }

    void UILayer::SetLightTheme()
    {
        ImGui::StyleColorsLight();
        ImGuiStyle &style = ImGui::GetStyle();

        style.Alpha = 1.0f;
        style.FrameRounding = 3.0f;
        style.Colors[ImGuiCol_Text]                 = ImVec4(0.00f, 0.00f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_TextDisabled]         = ImVec4(0.60f, 0.60f, 0.60f, 1.00f);
        style.Colors[ImGuiCol_WindowBg]             = ImVec4(0.94f, 0.94f, 0.94f, 0.94f);
        style.Colors[ImGuiCol_PopupBg]              = ImVec4(1.00f, 1.00f, 1.00f, 0.94f);
        style.Colors[ImGuiCol_Border]               = ImVec4(0.00f, 0.00f, 0.00f, 0.39f);
        style.Colors[ImGuiCol_BorderShadow]         = ImVec4(1.00f, 1.00f, 1.00f, 0.10f);
        style.Colors[ImGuiCol_FrameBg]              = ImVec4(1.00f, 1.00f, 1.00f, 0.94f);
        style.Colors[ImGuiCol_FrameBgHovered]       = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
        style.Colors[ImGuiCol_FrameBgActive]        = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
        style.Colors[ImGuiCol_TitleBg]              = ImVec4(0.96f, 0.96f, 0.96f, 1.00f);
        style.Colors[ImGuiCol_TitleBgCollapsed]     = ImVec4(1.00f, 1.00f, 1.00f, 0.51f);
        style.Colors[ImGuiCol_TitleBgActive]        = ImVec4(0.82f, 0.82f, 0.82f, 1.00f);
        style.Colors[ImGuiCol_MenuBarBg]            = ImVec4(0.86f, 0.86f, 0.86f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarBg]          = ImVec4(0.98f, 0.98f, 0.98f, 0.53f);
        style.Colors[ImGuiCol_ScrollbarGrab]        = ImVec4(0.69f, 0.69f, 0.69f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.59f, 0.59f, 0.59f, 1.00f);
        style.Colors[ImGuiCol_ScrollbarGrabActive]  = ImVec4(0.49f, 0.49f, 0.49f, 1.00f);
        style.Colors[ImGuiCol_CheckMark]            = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        style.Colors[ImGuiCol_SliderGrab]           = ImVec4(0.24f, 0.52f, 0.88f, 1.00f);
        style.Colors[ImGuiCol_SliderGrabActive]     = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        style.Colors[ImGuiCol_Button]               = ImVec4(0.26f, 0.59f, 0.98f, 0.40f);
        style.Colors[ImGuiCol_ButtonHovered]        = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        style.Colors[ImGuiCol_ButtonActive]         = ImVec4(0.06f, 0.53f, 0.98f, 1.00f);
        style.Colors[ImGuiCol_Header]               = ImVec4(0.26f, 0.59f, 0.98f, 0.31f);
        style.Colors[ImGuiCol_HeaderHovered]        = ImVec4(0.26f, 0.59f, 0.98f, 0.80f);
        style.Colors[ImGuiCol_HeaderActive]         = ImVec4(0.26f, 0.59f, 0.98f, 1.00f);
        style.Colors[ImGuiCol_ResizeGrip]           = ImVec4(1.00f, 1.00f, 1.00f, 0.50f);
        style.Colors[ImGuiCol_ResizeGripHovered]    = ImVec4(0.26f, 0.59f, 0.98f, 0.67f);
        style.Colors[ImGuiCol_ResizeGripActive]     = ImVec4(0.26f, 0.59f, 0.98f, 0.95f);
        style.Colors[ImGuiCol_PlotLines]            = ImVec4(0.39f, 0.39f, 0.39f, 1.00f);
        style.Colors[ImGuiCol_PlotLinesHovered]     = ImVec4(1.00f, 0.43f, 0.35f, 1.00f);
        style.Colors[ImGuiCol_PlotHistogram]        = ImVec4(0.90f, 0.70f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_PlotHistogramHovered] = ImVec4(1.00f, 0.60f, 0.00f, 1.00f);
        style.Colors[ImGuiCol_TextSelectedBg]       = ImVec4(0.26f, 0.59f, 0.98f, 0.35f);

        ImGuiIO &io = ImGui::GetIO();
        if (io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable)
        {
            style.WindowRounding = 10.0f;
            style.Colors[ImGuiCol_WindowBg].w = 1.0f;
        }
    }

    void UILayer::SetClassicTheme()
    {
        ImGui::StyleColorsClassic();
    }

}