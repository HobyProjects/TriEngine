#pragma once

#include "Camera2D.hpp"
#include "Camera3D.hpp"

#include "Timer.hpp"
#include "InputHandler.hpp"
#include "WindowEvents.hpp"
#include "MouseEvents.hpp"
#include "KeyCodes.hpp"

namespace TE::Camera
{
    class MainCamera
    {
        public:
            MainCamera(const Ref<TE::Core::Window>& window);
            ~MainCamera() = default;

            void OnUpdate(TE::Core::Timer deltaTime);
            void OnEvent(TE::Events::Event& event);
            void OnWindowResize(UInt32 width, UInt32 height);

        private:
            Boolean OnMouseWheelEvent(TE::Events::MouseScrollEvent& event);
            Boolean OnMouseCursorPosChangeEvent(TE::Events::MouseCursorPosChangeEvent& event);
            Boolean OnWindowResizeEvent(TE::Events::AppWindowResizeEvent& event);

        private:
            TE::Renderer::Camera3D m_Camera;

            Float m_ZoomLevel{1.0f};
            Float m_TranslationSpeed{100.0f};

            Double m_MouseY{0.0};
            Double m_MouseX{0.0};
            Float m_Sensitivity{10.0f};

            UInt32 m_WindowWidth{0};
            UInt32 m_WindowHeight{0};

            Ref<TE::Events::InputHandler> m_InputHandler;
    };
}
