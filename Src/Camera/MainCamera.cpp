#include "MainCamera.hpp"

namespace TE::Camera
{
    MainCamera::MainCamera(const Ref<TE::Core::Window>& window)
    {
        m_WindowWidth = window->GetWindowSpecification().Width;
        m_WindowHeight = window->GetWindowSpecification().Height;
        m_Camera.SetAspectRatio((Float)m_WindowWidth / (Float)m_WindowHeight);
        
        m_InputHandler = TE::Events::CreateInputHandler();
        m_InputHandler->TargetWindow(window);
    }

    void MainCamera::OnUpdate(TE::Core::Timer deltaTime)
    {
        if(m_InputHandler->IsKeyPressed(TE::Core::KEY_W))
        {
            Vec3 position = m_Camera.GetPosition();
            position += (m_TranslationSpeed * deltaTime) * m_Camera.GetOrientation();
            m_Camera.SetPosition(position);
        }

        if(m_InputHandler->IsKeyPressed(TE::Core::KEY_S))
        {
            Vec3 position = m_Camera.GetPosition();
            position += (m_TranslationSpeed * deltaTime) * -m_Camera.GetOrientation();
            m_Camera.SetPosition(position);
        }

        if(m_InputHandler->IsKeyPressed(TE::Core::KEY_A))
        {
            Vec3 position = m_Camera.GetPosition();
            position += (m_TranslationSpeed * deltaTime) * -glm::normalize(glm::cross(m_Camera.GetOrientation(), m_Camera.GetPerspectiveUp()));
            m_Camera.SetPosition(position);
        }

        if(m_InputHandler->IsKeyPressed(TE::Core::KEY_D))
        {
            Vec3 position = m_Camera.GetPosition();
            position += (m_TranslationSpeed * deltaTime) * glm::normalize(glm::cross(m_Camera.GetOrientation(), m_Camera.GetPerspectiveUp()));
            m_Camera.SetPosition(position);
        }

        if(m_InputHandler->IsKeyPressed(TE::Core::KEY_Q))
        {
            Vec3 position = m_Camera.GetPosition();
            position += (m_TranslationSpeed * deltaTime) * m_Camera.GetPerspectiveUp();
            m_Camera.SetPosition(position);
        }

        if(m_InputHandler->IsKeyPressed(TE::Core::KEY_E))
        {
            Vec3 position = m_Camera.GetPosition();
            position += (m_TranslationSpeed * deltaTime) * -m_Camera.GetPerspectiveUp();
            m_Camera.SetPosition(position);
        }  

        if(m_InputHandler->IsMouseButtonPressed(TE::Core::MOUSE_BUTTON_RIGHT))
        {
            Float rotationX = m_Sensitivity * (Float)(m_MouseY - (m_WindowHeight / 2)) / (Float)m_WindowHeight;
            Float rotationY = m_Sensitivity * (Float)(m_MouseX - (m_WindowWidth / 2)) / (Float)m_WindowWidth;

            Vec3 newOrientation = glm::rotate(m_Camera.GetOrientation(), glm::radians(-rotationX), glm::normalize(glm::cross(m_Camera.GetOrientation(), m_Camera.GetPerspectiveUp())));

            if (abs(glm::angle(newOrientation, m_Camera.GetPerspectiveUp()) - glm::radians(90.0f)) <= glm::radians(85.0f))
            {
                m_Camera.SetOrientation(newOrientation);
            }

            m_Camera.SetOrientation(glm::rotate(m_Camera.GetOrientation(), glm::radians(-rotationY), m_Camera.GetPerspectiveUp()));
        }
    }

    void MainCamera::OnEvent(TE::Events::Event & event)
    {
        TE::Events::EventHandler handler(event);
        handler.Dispatch<TE::Events::MouseScrollEvent>(TRIMANA_EVENT_CALLBACK(MainCamera::OnMouseWheelEvent));
        handler.Dispatch<TE::Events::MouseCursorPosChangeEvent>(TRIMANA_EVENT_CALLBACK(MainCamera::OnMouseCursorPosChangeEvent));
        handler.Dispatch<TE::Events::AppWindowResizeEvent>(TRIMANA_EVENT_CALLBACK(MainCamera::OnWindowResizeEvent));
    }

    void MainCamera::OnWindowResize(UInt32 width, UInt32 height)
    {
        m_WindowWidth = width;
        m_WindowHeight = height;
        m_Camera.SetAspectRatio((Float)m_WindowWidth / (Float)m_WindowHeight);
    }

    Boolean MainCamera::OnMouseWheelEvent(TE::Events::MouseScrollEvent & event)
    {
        m_ZoomLevel -= event.GetMouseScrollOffsetY();
        m_ZoomLevel = std::max(m_ZoomLevel, 0.25f);

        if(m_InputHandler->IsMouseButtonPressed(TE::Core::MOUSE_BUTTON_RIGHT))
        {
            //TODO: Implement to change translation speed when scrolling
        }

        return TE_FALSE;
    }

    Boolean MainCamera::OnMouseCursorPosChangeEvent(TE::Events::MouseCursorPosChangeEvent & event)
    {
        m_MouseX = event.GetMousePosX();
        m_MouseY = event.GetMousePosY();
        return TE_FALSE;
    }

    Boolean MainCamera::OnWindowResizeEvent(TE::Events::AppWindowResizeEvent & event)
    {
        OnWindowResize(event.GetWidth(), event.GetHeight());
        return TE_FALSE;
    }
}