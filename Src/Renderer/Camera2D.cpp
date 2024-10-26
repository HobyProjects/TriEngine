#include "Camera2D.hpp"

namespace TE::Renderer
{
    Camera2D::Camera2D(float left, float right, float bottom, float top){
        m_Projection = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
        m_ViewProjection = m_Projection * m_View;
    }

    void Camera2D::SetRotation(float rotation){
        m_Rotation = rotation;
        RecalculateViewMatrix();
    }

    void Camera2D::SetPosition(const Vec3& position){
        m_Position = position;
        RecalculateViewMatrix();
    }

    void Camera2D::SetProjection(float left, float right, float bottom, float top){
        m_Projection = glm::ortho(left, right, bottom, top, -1.0f, 1.0f);
        m_ViewProjection = m_Projection * m_View;
    }

    void Camera2D::RecalculateViewMatrix(){
        Mat4 transform = glm::translate(glm::mat4(1.0f), m_Position) * glm::rotate(glm::mat4(1.0f), glm::radians(m_Rotation), {0.0f, 0.0f, 1.0f});
        Mat4 view = glm::inverse(transform);
        m_ViewProjection = view * m_Projection;
    }
}