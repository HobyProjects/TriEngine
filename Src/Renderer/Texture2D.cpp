#include "Texture2D.hpp"
#include "Renderer.hpp"

#include "OpenGL/OpenGL.hpp"

namespace TE::Renderer
{
    Ref<ITexture2D> CreateTexture2D(Int32 width, Int32 height)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:             TRIMANA_ASSERT(TE_FALSE, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:           return std::make_shared<TE::APIs::OpenGL::GL_Texture2D>(width, height);
            case RendererAPI::Vulkan:           TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:          TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            default:                            return nullptr;
        };
    }

    Ref<ITexture2D> CreateTexture2D(const Path& path, Boolean flip)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:             TRIMANA_ASSERT(TE_FALSE, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:           return std::make_shared<TE::APIs::OpenGL::GL_Texture2D>(path, flip);
            case RendererAPI::Vulkan:           TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:          TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            default:                            return nullptr;
        };
    }

   Ref<ISubTexture2D> CreateSubTexture2D(const Ref<ITexture2D>& texture, const Vec2& coords, const Vec2 & cellSize, const Vec2& spriteSize)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:             TRIMANA_ASSERT(TE_FALSE, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:
            {
                float textureWidth = static_cast<float>(texture->GetWidth());
                float textureHeight = static_cast<float>(texture->GetHeight());
                glm::vec2 min = { (coords.x * cellSize.x) / textureWidth, (coords.y * cellSize.y) / textureHeight };
                glm::vec2 max = { ((coords.x + spriteSize.x) * cellSize.x) / textureWidth, ((coords.y + spriteSize.y) * cellSize.y) / textureHeight };
                return std::make_shared<TE::APIs::OpenGL::GL_SubTexture2D>(texture, min, max);
            }
            case RendererAPI::Vulkan:           TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:          TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            default:                            return nullptr;
        };
    }


}