#pragma once

#include "Base.hpp"
#include "TypeDef.hpp"

namespace TE::Renderer
{
    enum class RendererAPI
    {
        None        = TE_BIT(0),
        OpenGL      = TE_BIT(1),
        Vulkan      = TE_BIT(2),
        DirectX     = TE_BIT(3)
    };

    class Renderer
    {
        private:
            Renderer() = default;
            ~Renderer() = default;

        public:
            static void Init();
            static void Shutdown();

            static RendererAPI GetAPI();
            static void ChangeAPI(RendererAPI api);
            static void Clear();
            static void ClearColor(const Vec4& color);
            static void SetViewport(UInt32 x, UInt32 y, UInt32 width, UInt32 height);
    };
}