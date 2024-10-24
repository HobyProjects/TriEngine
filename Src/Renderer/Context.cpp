#include "Context.hpp"

#include "Renderer.hpp"
#include "OpenGL/OpenGL.hpp"

namespace TE::Renderer
{
    std::shared_ptr<Context> CreateContext(WindowAPIPtr window)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:         TRIMANA_ASSERT(false, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:       return std::make_shared<TE::APIs::OpenGL::GL_Context>(window);
            case RendererAPI::Vulkan:       TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:      TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            default:                        return nullptr;
        };
    }
}