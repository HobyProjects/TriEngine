#pragma once 

#include "TypeDef.hpp"

namespace TE::Renderer
{
    enum class CameraType
    {
        Camera_2D = 0,
        Camera_3D = 1
    };

    struct CameraBounds
    {
        Float Left{ 0.0f };
        Float Right{ 0.0f };
        Float Top{ 0.0f };
        Float Bottom{ 0.0f };

        CameraBounds() = default;
        CameraBounds(Float left, Float right, Float top, Float bottom) : Left(left), Right(right), Top(top), Bottom(bottom) {};
        ~CameraBounds() = default;

        Float Width() const { return Right - Left; }
        Float Height() const { return Bottom - Top; }
    };


    class Camera
    {
        public:
            Camera() = default;
            virtual ~Camera() = default;

        protected:
            Mat4 m_Projection{1.0f};
            Mat4 m_View{1.0f};
            Vec3 m_Position{0.0f, 0.0f, 0.0f};
            Float m_Rotation{0.0f};
    };
}