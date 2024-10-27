#pragma once

#include "TypeDef.hpp"
#include "Camera.hpp"

namespace TE::Renderer
{
    class Camera3D : public Camera
    {
        public:
            Camera3D() = default;
            Camera3D(Float fov = 45.0f, Float nearClip = 0.01f, Float farClip = 1000.0f);
            virtual ~Camera3D() = default;

            CameraType GetCameraType() const { return CameraType::Camera_3D; }

            void SetAspectRatio(Float ratio);
            void SetRotation(Float rotation);
            void SetPosition(const Vec3& position);
            void SetOrientation(const Vec3& orientation);
            void SetPerspectiveUp(const Vec3& up);
            void SetPerspective(Float fov = 45.0f, Float nearClip = 0.01f, Float farClip = 1000.0f);

            const Vec3& GetPosition() const { return m_Position; }
            const Vec3& GetOrientation() const { return m_Orientation; }
            const Vec3& GetPerspectiveUp() const { return m_PerspectiveUp; }
            const Mat4& GetView() const { return m_View; }
            const Mat4& GetProjection() const { return m_Projection; }
            const Mat4& GetViewProjection() const { return m_ViewProjection; }

            Float GetPerspectiveFov() const { return m_PerspectiveFov; }
            Float GetPerspectiveNear() const { return m_PerspectiveNear; }
            Float GetPerspectiveFar() const { return m_PerspectiveFar; }
            Float GetAspectRatio() const { return m_AspectRatio; }

        private:
            void RefreshViewProjectionMatrix();

        private:
            Mat4 m_ViewProjection{1.0f};
            Vec3 m_Orientation{0.0f, 0.0f, -1.0f};
            Vec3 m_PerspectiveUp{0.0f, 1.0f, 0.0f};

            Float m_AspectRatio{0.0f};
            Float m_PerspectiveFov{45.0f};
            Float m_PerspectiveNear{0.01f};
            Float m_PerspectiveFar{1000.0f};
    };

}