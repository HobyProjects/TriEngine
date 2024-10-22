#pragma once

#include "TypeDef.hpp"

namespace TE::Core
{
    class Timer
    {
        public:
            Timer() = default;
            Timer(Float32 deltaTime) : m_DeltaTime(deltaTime) {}
            ~Timer() = default;

            Float32 GetDeltaTime() const { return m_DeltaTime; }
            Float32 GetDeltaTimeSeconds() const { return m_DeltaTime; }
            Float32 GetDeltaTimeInMilliseconds() const { return m_DeltaTime * 1000.0f; }

            operator Float32() const { return m_DeltaTime; }

        private:
            Float32 m_DeltaTime{0.0f};
    };
}