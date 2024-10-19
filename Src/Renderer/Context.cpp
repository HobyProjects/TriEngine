#include "Context.hpp"

#include "Renderer.hpp"
#include "OpenGL.hpp"

namespace TE::Renderer
{
    std::shared_ptr<Context> CreateContext(void* window)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None: TRIMANA_ASSERT(false, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL: return std::make_shared<TE::APIs::OpenGL::GL_Context>(window);
            default: return nullptr;
        };
    }
}