#pragma once

#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_internal.h>

#include "Layer.hpp"
#include "Window.hpp"

namespace TE::UI
{
    enum class UITheme
    {
        Dark    = 0,   
        Light   = 1,    
        Classic = 2     
    };

    class UILayer final : TE::Core::Layer
    {
        public:
            UILayer() : TE::Core::Layer("UILayer"){}
            UILayer(Ref<TE::Core::Window> window, UITheme theme = UITheme::Dark);
            virtual ~UILayer() = default;

            virtual void OnAttach() override;
            virtual void OnDetach() override;
            virtual void OnEvent(TE::Events::Event& event) override;
            void Begin();
            void End();
            void AllowEvents(Boolean allowEvents);
            void SetTheme(UITheme theme);

        private:
            void SetDarkTheme();
            void SetLightTheme();
            void SetClassicTheme();

        private:
            Ref<TE::Core::Window> m_Window{nullptr};
            Boolean m_AllowEvents{TE_TRUE};
            UITheme m_Theme{UITheme::Dark};
    };
}