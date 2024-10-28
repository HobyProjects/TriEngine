#include "Context.hpp"

#include "Renderer.hpp"
#include "OpenGL/OpenGL.hpp"

namespace TE::Renderer
{
    Ref<Context> CreateContext(NativeWindow window)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:         TRIMANA_ASSERT(TE_FALSE, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:       return CreateRef<TE::APIs::OpenGL::GL_Context>(window);
            case RendererAPI::Vulkan:       TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:      TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            default:                        return nullptr;
        };
    }
}