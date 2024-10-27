#pragma once

#include "TypeDef.hpp"
#include "Timer.hpp"
#include "Events.hpp"

namespace TE::Core
{
    class Layer
    {
        public:
            Layer(const String& name) : m_Name(name) {}
            virtual ~Layer() = default;

            virtual void OnAttach() {}
            virtual void OnDetach() {}
            virtual void OnUpdate(Timer deltaTime) {}
            virtual void OnEvent(TE::Events::Event& event) {}
            virtual void OnGuiRendering() {}
            const String& GetName() const { return m_Name; }

        protected:
            String m_Name{String("Unknown")};
    };
}