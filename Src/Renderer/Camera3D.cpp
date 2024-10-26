#include "Camera3D.hpp"

namespace TE::Renderer
{
    Camera3D::Camera3D(Float fov, Float nearClip, Float farClip)
    {
        m_PerspectiveFov    = fov;
        m_PerspectiveNear   = nearClip;
        m_PerspectiveFar    = farClip;
        RefreshViewProjectionMatrix();
    }

    void Camera3D::SetAspectRatio(Float ratio)
    {
        m_AspectRatio = ratio;
        RefreshViewProjectionMatrix();
    }

    void Camera3D::SetRotation(Float rotation)
    {
        m_Rotation = rotation;
        RefreshViewProjectionMatrix();
    }

    void Camera3D::SetPosition(const Vec3 & position)
    {
        m_Position = position;
        RefreshViewProjectionMatrix();
    }

    void Camera3D::SetOrientation(const Vec3 & orientation)
    {
        m_Orientation = orientation;
        RefreshViewProjectionMatrix();
    }

    void Camera3D::SetPerspectiveUp(const Vec3 & up)
    {
        m_PerspectiveUp = up;
        RefreshViewProjectionMatrix();
    }

    void Camera3D::SetPerspective(Float fov, Float nearClip, Float farClip)
    {
        m_PerspectiveFov    = fov;
        m_PerspectiveNear   = nearClip;
        m_PerspectiveFar    = farClip;
        RefreshViewProjectionMatrix();
    }

    void Camera3D::RefreshViewProjectionMatrix()
    {
        m_View = Maths::lookAt(m_Position, m_Position + m_Orientation, m_PerspectiveUp);
        m_Projection = Maths::perspective(m_PerspectiveFov, m_AspectRatio, m_PerspectiveNear, m_PerspectiveFar);
        m_ViewProjection = m_View * m_Projection;
    }
}