#include "OpenGL/OpenGL.hpp"
#include "Shaders.hpp"
#include "Renderer.hpp"

namespace TE::Renderer
{
    std::shared_ptr<Shader> CreateShader(const String & name, const Path & vtxShader, const Path & fragShader)
    {
        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:             TRIMANA_ASSERT(false, "No rendering API selected"); return nullptr;
            case RendererAPI::OpenGL:           return std::make_shared<TE::APIs::OpenGL::GL_Shader>(name, vtxShader, fragShader);
            case RendererAPI::Vulkan:           TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            case RendererAPI::DirectX:          TRIMANA_ASSERT(false, "Not implemented yet"); return nullptr;
            default:                            return nullptr;
        };
    }

}