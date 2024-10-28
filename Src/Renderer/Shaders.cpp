#include "OpenGL/OpenGL.hpp"
#include "Shaders.hpp"
#include "Renderer.hpp"

namespace TE::Renderer
{
    Ref<Shader> CreateShader(const String& name, const Path& vtxShader, const Path& fragShader)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:             TRIMANA_ASSERT(TE_FALSE, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:           return CreateRef<TE::APIs::OpenGL::GL_Shader>(name, vtxShader, fragShader);
            case RendererAPI::Vulkan:           TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:          TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); return nullptr;
            default:                            return nullptr;
        };
    }

}