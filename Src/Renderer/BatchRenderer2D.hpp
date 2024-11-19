#pragma once

#include <array>

#include "TypeDef.hpp"
#include "VertexArray.hpp"
#include "Buffers.hpp"
#include "Texture2D.hpp"
#include "Shaders.hpp"
#include "Camera2D.hpp"
#include "Renderer.hpp"

#include "OpenGL/OpenGL.hpp"

namespace TE::Renderer
{
    class BatchRenderer2D
    {
        private:
            BatchRenderer2D() = default;
            ~BatchRenderer2D() = default;

            static void Restart();

        public:
            static void Init();
            static void Shutdown();

            static void Begin(const Camera2D& camera, const Mat4& transform);
            static void End();
            static void Flush();

            static void DrawQuad(const Vec2& position, const Vec2& size, const Vec4& color);
            static void DrawQuad(const Vec2& position, const Vec2& size, const Vec4& color, Float rotation);
            static void DrawQuad(const Vec2& position, const Vec2& size, const Ref<Texture2D>& texture);
            static void DrawQuad(const Vec2& position, const Vec2& size, const Ref<Texture2D>& texture, Float rotation);
            static void DrawQuad(const Vec2& position, const Vec2& size, const Vec4& color, const Ref<Texture2D>& texture, Float tilingFactor = 1.0f);
            static void DrawQuad(const Vec2& position, const Vec2& size, const Vec4& color, const Ref<Texture2D>& texture, Float rotation = 1.0f, Float tilingFactor = 1.0f);
            static void DrawQuad(const Vec2& position, const Vec2& size, const glm::vec4& color, const Ref<SubTexture2D>& texture, Float rotation, Float tilingFactor = 1.0f);

            static void DrawQuad(const Mat4& transform, const Vec4& color);
            static void DrawQuad(const Mat4& transform, const Ref<Texture2D>& texture, const Vec4& tint = Vec4(1.0f), Float tilingFactor = 1.0f);
            static void DrawQuad(const Mat4& transform, const Ref<SubTexture2D>& texture, const Vec4& tint = Vec4(1.0f), Float tilingFactor = 1.0f);

            struct Status 
            {
                UInt32 DrawCount{TE_NULL};
                UInt32 QuadCount{TE_NULL};
            };

            static const Status& RenderingStatus();
            static void StatusReset();
    };
}