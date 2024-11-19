#include "Renderer.hpp"
#include "Asserts.hpp"

#include "OpenGL/OpenGL.hpp"

namespace TE::Renderer
{
    static RendererAPI s_RendererAPI = RendererAPI::OpenGL;

    void Renderer::Init()
    {
        switch(s_RendererAPI)
        {
            case RendererAPI::OpenGL:
            {
                TE::APIs::OpenGL::GL_Renderer::Init();
                break;
            }
            case RendererAPI::Vulkan:
            {
                TRIMANA_ASSERT(false, "Not implemented yet");
                break;
            }
            case RendererAPI::DirectX:
            {
                TRIMANA_ASSERT(false, "Not implemented yet");
                break;
            }
            default:
            {
                break;
            }
        }
    }
    void Renderer::Shutdown()
    {
        switch(s_RendererAPI)
        {
            case RendererAPI::OpenGL:
            {
                TE::APIs::OpenGL::GL_Renderer::Shutdown();
                break;
            }
            case RendererAPI::Vulkan:
            {
                TRIMANA_ASSERT(false, "Not implemented yet");
                break;
            }
            case RendererAPI::DirectX:
            {
                TRIMANA_ASSERT(false, "Not implemented yet");
                break;
            }
            default:
            {
                break;
            }
        }
    }

    RendererAPI Renderer::GetAPI()
    {
        return s_RendererAPI;
    }

    void Renderer::ChangeAPI(RendererAPI api)
    {
        s_RendererAPI = api;
    }

    void Renderer::Clear()
    {
        switch(s_RendererAPI)
        {
            case RendererAPI::OpenGL:
            {
                TE::APIs::OpenGL::GL_Renderer::Clear();
                break;
            }
            case RendererAPI::Vulkan:
            {
                TRIMANA_ASSERT(false, "Not implemented yet");
                break;
            }
            case RendererAPI::DirectX:
            {
                TRIMANA_ASSERT(false, "Not implemented yet");
                break;
            }
            default:
            {
                break;
            }
        }
    }

    void Renderer::ClearColor(const Vec4& color)
    {
        switch(s_RendererAPI)
        {
            case RendererAPI::OpenGL:
            {
                TE::APIs::OpenGL::GL_Renderer::ClearColor(color);
                break;
            }
            case RendererAPI::Vulkan:
            {
                TRIMANA_ASSERT(false, "Not implemented yet");
                break;
            }
            case RendererAPI::DirectX:
            {
                TRIMANA_ASSERT(false, "Not implemented yet");
                break;
            }
            default:
            {
                break;
            }
        }
    }

    void Renderer::SetViewport(UInt32 x, UInt32 y, UInt32 width, UInt32 height)
    {
        switch(s_RendererAPI)
        {
            case RendererAPI::OpenGL:
            {
                TE::APIs::OpenGL::GL_Renderer::SetViewport(x, y, width, height);
                break;
            }
            case RendererAPI::Vulkan:
            {
                TRIMANA_ASSERT(false, "Not implemented yet");
                break;
            }
            case RendererAPI::DirectX:
            {
                TRIMANA_ASSERT(false, "Not implemented yet");
                break;
            }
            default:
            {
                break;
            }
        }
    }
}