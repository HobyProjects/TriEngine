#include "OpenGL.hpp"
#include "Renderer.hpp"
#include "Buffers.hpp"

namespace TE::Renderer
{
    std::shared_ptr<VertexBuffer> CreateVertexBuffer(UInt32 allocatorSize)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:         TRIMANA_ASSERT(false, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:       return std::make_shared<TE::APIs::OpenGL::GL_VertexBuffer>(allocatorSize);
            case RendererAPI::Vulkan:       TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:      TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            default:                        return nullptr;
        }
    }

    std::shared_ptr<VertexBuffer> CreateVertexBuffer(VertexBufferData data, UInt32 size)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:         TRIMANA_ASSERT(false, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:       return std::make_shared<TE::APIs::OpenGL::GL_VertexBuffer>(data, size);
            case RendererAPI::Vulkan:       TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:      TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            default:                        return nullptr;
        }
    }

    std::shared_ptr<IndexBuffer> CreateIndexBuffer(IndexBufferData data, UInt32 count)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:         TRIMANA_ASSERT(false, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:       return std::make_shared<TE::APIs::OpenGL::GL_IndexBuffer>(data, count);
            case RendererAPI::Vulkan:       TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:      TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            default:                        return nullptr;
        }
    }

}