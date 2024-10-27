#include "OpenGL/OpenGL.hpp"
#include "Renderer.hpp"
#include "Buffers.hpp"

namespace TE::Renderer
{
    Ref<IVertexBuffer> CreateVertexBuffer(UInt32 allocatorSize)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:         TRIMANA_ASSERT(TE_FALSE, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:       return CreateRef<TE::APIs::OpenGL::GL_VertexBuffer>(allocatorSize);
            case RendererAPI::Vulkan:       TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:      TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            default:                        return nullptr;
        }
    }

    Ref<IVertexBuffer> CreateVertexBuffer(VertexBufferData data, UInt32 size)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:         TRIMANA_ASSERT(TE_FALSE, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:       return CreateRef<TE::APIs::OpenGL::GL_VertexBuffer>(data, size);
            case RendererAPI::Vulkan:       TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:      TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            default:                        return nullptr;
        }
    }

    Ref<IIndexBuffer> CreateIndexBuffer(IndexBufferData data, UInt32 count)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:         TRIMANA_ASSERT(TE_FALSE, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:       return CreateRef<TE::APIs::OpenGL::GL_IndexBuffer>(data, count);
            case RendererAPI::Vulkan:       TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:      TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            default:                        return nullptr;
        }
    }

}