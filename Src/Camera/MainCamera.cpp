#include "MainCamera.hpp"

namespace TE::Camera
{
    MainCamera::MainCamera(const Ref<TE::Core::Window>& window)
    {
        m_Camera3D.SetAspectRatio((Float)window->GetWindowSpecification().Width / (Float)window->GetWindowSpecification().Height);
        m_Bounds = { -m_Camera3D.GetAspectRatio() * m_ZoomLevel, m_Camera3D.GetAspectRatio() * m_ZoomLevel, -m_ZoomLevel, m_ZoomLevel };
        
        m_InputHandler = TE::Events::CreateInputHandler();
        m_InputHandler->TargetWindow(window);
    }

    void MainCamera::OnUpdate(TE::Core::Timer deltaTime)
    {
        if(m_InputHandler->IsKeyPressed(TE::Core::KEY_W))
        {
        }

        if(m_InputHandler->IsKeyPressed(TE::Core::KEY_S))
        {
        }

        if(m_InputHandler->IsKeyPressed(TE::Core::KEY_A))
        {
        }

        if(m_InputHandler->IsKeyPressed(TE::Core::KEY_D))
        {
        }

        if(m_InputHandler->IsKeyPressed(TE::Core::KEY_Q))
        {
        }

        if(m_InputHandler->IsKeyPressed(TE::Core::KEY_E))
        {
        }
            
    }


}