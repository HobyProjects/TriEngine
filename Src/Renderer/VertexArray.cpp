#include "Renderer.hpp"
#include "OpenGL/OpenGL.hpp"
#include "VertexArray.hpp"

namespace TE::Renderer
{
    std::shared_ptr<VertexArray> TE::Renderer::CreateVertexArray()
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:         TRIMANA_ASSERT(false, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:       return std::make_shared<TE::APIs::OpenGL::GL_VertexArray>();
            case RendererAPI::Vulkan:       TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:      TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            default:                        return nullptr;
        };
    }
}