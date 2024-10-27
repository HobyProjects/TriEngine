#include "Renderer.hpp"
#include "OpenGL/OpenGL.hpp"
#include "FrameBuffer.hpp"

namespace TE::Renderer
{
    Ref<IFrameBuffer> TE::Renderer::CreateFrameBuffer(const FrameBufferSpecifications & specification)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:         TRIMANA_ASSERT(false, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:       return CreateRef<TE::APIs::OpenGL::GL_FrameBuffer>(specification);
            case RendererAPI::Vulkan:       TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:      TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            default:                        return nullptr;
        }
    }

}