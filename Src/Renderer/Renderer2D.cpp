#include "Renderer2D.hpp"

namespace TE::Renderer
{
    static const UInt32 MAX_QUADS                 = 20000;
    static const UInt32 MAX_VERTICES              = MAX_QUADS * 4;
    static const UInt32 MAX_INDICES               = MAX_QUADS * 6;
    static const UInt32 MAX_TEXTURE_SLOTS         = 32;
    static const UInt32 MAX_QUAD_VERTEX_COUNT     = 4;
    static const Vec4 DEFAULT_COLOR               = { 1.0f, 1.0f, 1.0f, 1.0f };
    static const Vec2 DEFAULT_TEX_COORDS[]        = { { 0.0f, 0.0f }, { 1.0f, 0.0f }, { 1.0f, 1.0f }, { 0.0f, 1.0f } };

    struct Vertex 
    {
		Vec3 Position;
		Vec4 Color;
		Vec2 TexCoords;
		Float TexIndex;
		Float TilingFactor;
	};

    struct BatchData 
    {
        Ref<VertexArray> QuadVAO{ nullptr };
        Ref<VertexBuffer> QuadVBO{ nullptr };
        Ref<IndexBuffer> QuadIBO{ nullptr };

        Ref<Texture2D> PlainTexture{ nullptr };
        UInt32 PlainTextureSlot{ TE_NULL };
        UInt32 IndexCount{ TE_NULL };

        Vertex* QuadBuffer{ nullptr };
        Vertex* QuadBufferPtr{ nullptr };

        Ref<Shader> BatchShader{ nullptr };
        std::array<Ref<Texture2D>, MAX_TEXTURE_SLOTS> TextureSlots;
        UInt32 TextureSlotIndex{ 1 };

        Renderer2D::Status RenderingStatus;
        Vec4 QuadVertexPositions[MAX_QUAD_VERTEX_COUNT];

    }; static BatchData s_BatchData;

    void Renderer2D::Restart() 
    {
        End();
        s_BatchData.QuadBufferPtr = s_BatchData.QuadBuffer;
        s_BatchData.IndexCount = 0;
        s_BatchData.TextureSlotIndex = 1;
    }

    void Renderer2D::Init()
    {
        s_BatchData.QuadBuffer = new Vertex[MAX_VERTICES];
        s_BatchData.QuadVAO = CreateVertexArray();
        s_BatchData.QuadVAO->Bind();
        {
            s_BatchData.QuadVBO = CreateVertexBuffer(MAX_VERTICES * sizeof(Vertex));
            s_BatchData.QuadVBO->Bind();
            {
                s_BatchData.QuadVBO->SetLayout({
                    {"u_Position", BufferComponents::XYZ, BufferStride::F3, TE_FALSE },
                    {"u_Color", BufferComponents::RGBA, BufferStride::F4, TE_FALSE },
                    {"u_TexCoords", BufferComponents::UV, BufferStride::F2, TE_FALSE },
                    {"u_TexIndex", BufferComponents::X, BufferStride::F1, TE_FALSE },
                    {"u_TilingFactor", BufferComponents::X, BufferStride::F1, TE_FALSE }
                });

                s_BatchData.QuadVAO->EmplaceVtxBuffer(s_BatchData.QuadVBO);

                UInt32 indices[MAX_INDICES];
                UInt32 offset = 0;
                for(UInt32 i = 0; i < MAX_INDICES; i += 6)
                {
                    indices[i + 0] = offset + 0;
                    indices[i + 1] = offset + 1;
                    indices[i + 2] = offset + 2;
                    indices[i + 3] = offset + 2;
                    indices[i + 4] = offset + 3;
                    indices[i + 5] = offset + 0;
                    offset += 4;
                }

                s_BatchData.QuadIBO = CreateIndexBuffer(indices, MAX_INDICES);
                s_BatchData.QuadVAO->EmplaceIdxBuffer(s_BatchData.QuadIBO);

                for(UInt32 i = 0; i < MAX_TEXTURE_SLOTS; i++)
                    s_BatchData.TextureSlots[i] = nullptr;

                s_BatchData.PlainTexture = CreateTexture2D(1, 1);
                s_BatchData.TextureSlots[0] = s_BatchData.PlainTexture;

                //TODO: Create a Asset Manager to load shaders
                s_BatchData.BatchShader = CreateShader("Renderer2D-GL-DefaultShaders", "Assets/Shaders/Renderer2D-Vertex.glsl", "Assets/Shaders/Renderer2D-Fragment.glsl");

                s_BatchData.QuadVertexPositions[0] = { -0.5f, -0.5f, 0.0f, 1.0f };
                s_BatchData.QuadVertexPositions[1] = {  0.5f, -0.5f, 0.0f, 1.0f };
                s_BatchData.QuadVertexPositions[2] = {  0.5f,  0.5f, 0.0f, 1.0f };
                s_BatchData.QuadVertexPositions[3] = { -0.5f,  0.5f, 0.0f, 1.0f };
            }
        }
        s_BatchData.QuadVAO->Unbind();
    }
    void Renderer2D::Shutdown()
    {
        delete[] s_BatchData.QuadBuffer;
    }

    void Renderer2D::Begin(const Camera2D& camera, const Mat4& transform)
    {
        s_BatchData.BatchShader->Bind();
        s_BatchData.BatchShader->SetUniform("u_MVP", camera.GetViewProjection());

        UInt32 texture_location = s_BatchData.BatchShader->GetUniformLocation("u_Textures");
        Int32 samplers[MAX_TEXTURE_SLOTS];
        for(UInt32 i = 0; i < MAX_TEXTURE_SLOTS; i++) 
            samplers[i] = i;

        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:         TRIMANA_ASSERT(TE_FALSE, "No rendering API selected"); break;
            case RendererAPI::OpenGL:       glUniform1iv(texture_location, MAX_TEXTURE_SLOTS, samplers); break;
            case RendererAPI::Vulkan:       TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); break;
            case RendererAPI::DirectX:      TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); break;
            default:                        break;
        };

        s_BatchData.QuadBufferPtr = s_BatchData.QuadBuffer;
    }

    void Renderer2D::End()
    {
        UInt32 size = (UInt8*)s_BatchData.QuadBufferPtr - (UInt8*)s_BatchData.QuadBuffer;
        s_BatchData.QuadVBO->Bind();
        s_BatchData.QuadVBO->SetData(s_BatchData.QuadBuffer, size);
        Flush();
    }

    void Renderer2D::Flush()
    {
        for(UInt32 i = 0; i < s_BatchData.TextureSlotIndex; i++) 
        {
            s_BatchData.TextureSlots[i]->Bind(i);
		}

        s_BatchData.QuadVAO->Bind();

        switch(Renderer::GetAPI())
        {
            case RendererAPI::None:         TRIMANA_ASSERT(TE_FALSE, "No rendering API selected"); break;
            case RendererAPI::OpenGL:       glDrawElements(GL_TRIANGLES, s_BatchData.IndexCount, GL_UNSIGNED_INT, nullptr); break;
            case RendererAPI::Vulkan:       TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); break;
            case RendererAPI::DirectX:      TRIMANA_ASSERT(TE_FALSE, "Not implemented yet"); break;
            default:                        break;
        };

        s_BatchData.RenderingStatus.DrawCount++;
		s_BatchData.IndexCount = 0;
		s_BatchData.TextureSlotIndex = 1;
    }

    void Renderer2D::DrawQuad(const Vec2& position, const Vec2& size, const Vec4& color)
    {
        DrawQuad(position, size, color, s_BatchData.PlainTexture, 0.0f, 1.0f);
    }

    void Renderer2D::DrawQuad(const Vec2& position, const Vec2& size, const Vec4& color, Float rotation)
    {
        DrawQuad(position, size, color, s_BatchData.PlainTexture, rotation, 1.0f);
    }

    void Renderer2D::DrawQuad(const Vec2& position, const Vec2& size, const Ref<Texture2D>& texture)
    {
        DrawQuad(position, size, Vec4(1.0f), texture, 0.0f, 1.0f);
    }

    void Renderer2D::DrawQuad(const Vec2& position, const Vec2& size, const Ref<Texture2D>& texture, Float rotation)
    {
        DrawQuad(position, size, Vec4(1.0f), texture, rotation, 1.0f);
    }

    void Renderer2D::DrawQuad(const Vec2& position, const Vec2 & size, const Vec4& color, const Ref<Texture2D>& texture, Float tilingFactor)
    {
        DrawQuad(position, size, color, texture, 0.0f, tilingFactor);
    }

    void Renderer2D::DrawQuad(const Vec2& position, const Vec2& size, const Vec4& color, const Ref<Texture2D>& texture, Float rotation, Float tilingFactor)
    {
        if (s_BatchData.IndexCount >= MAX_INDICES || s_BatchData.TextureSlotIndex >= MAX_TEXTURE_SLOTS) 
        {
            Restart();
        }

        Float texture_index = 0.0f;
        for(UInt32 i = 1; i < s_BatchData.TextureSlotIndex; i++) 
        {
			if (s_BatchData.TextureSlots[i] == texture) 
            {
				texture_index = static_cast<Float>(i);
				break;
			}
		}

        if(texture_index == 0.0f) 
        {
			texture_index = static_cast<Float>(s_BatchData.TextureSlotIndex);
			s_BatchData.TextureSlots[s_BatchData.TextureSlotIndex] = texture;
			s_BatchData.TextureSlotIndex++;
		}

        Mat4 transform = glm::translate(Mat4(1.0f), { position.x, position.y, 0.0f }) * glm::rotate(Mat4(1.0f), rotation, { 0.0f, 0.0f, 1.0f }) * glm::scale(Mat4(1.0f), { size.x, size.y, 1.0f });

		for(UInt32 i = 0; i < MAX_QUAD_VERTEX_COUNT; i++) 
        {
			s_BatchData.QuadBufferPtr->Position             = transform * s_BatchData.QuadVertexPositions[i];
			s_BatchData.QuadBufferPtr->Color                = color;
			s_BatchData.QuadBufferPtr->TexCoords            = DEFAULT_TEX_COORDS[i];
			s_BatchData.QuadBufferPtr->TexIndex             = texture_index;
			s_BatchData.QuadBufferPtr->TilingFactor         = tilingFactor;
			s_BatchData.QuadBufferPtr++;
		}

		s_BatchData.IndexCount += 6;
		s_BatchData.RenderingStatus.QuadCount++;
    }

    void Renderer2D::DrawQuad(const Vec2& position, const Vec2& size, const glm::vec4& color, const Ref<SubTexture2D>& texture, Float rotation, Float tilingFactor)
    {
        if (s_BatchData.IndexCount >= MAX_INDICES || s_BatchData.TextureSlotIndex >= MAX_TEXTURE_SLOTS) 
        {
			Restart();
		}

        const Vec2* tex_coords = texture->GetTextureCoords();
        Float texture_index = 0.0f;

        for (UInt32 i = 1; i < s_BatchData.TextureSlotIndex; i++) 
        {
            if (s_BatchData.TextureSlots[i] == texture->GetTexturePtr()) {
                texture_index = static_cast<Float>(i);
                break;
            }
        }

        if(texture_index == 0.0f) 
        {
			texture_index = static_cast<Float>(s_BatchData.TextureSlotIndex);
			s_BatchData.TextureSlots[s_BatchData.TextureSlotIndex] = texture->GetTexturePtr();
			s_BatchData.TextureSlotIndex++;
		}

        Mat4 transform = glm::translate(Mat4(1.0f), { position.x, position.y, 0.0f }) * glm::rotate(Mat4(1.0f), rotation, { 0.0f, 0.0f, 1.0f }) * glm::scale(Mat4(1.0f), { size.x, size.y, 1.0f });

		for (UInt32 i = 0; i < MAX_QUAD_VERTEX_COUNT; i++) 
        {
			s_BatchData.QuadBufferPtr->Position         = transform * s_BatchData.QuadVertexPositions[i];
			s_BatchData.QuadBufferPtr->Color            = color;
			s_BatchData.QuadBufferPtr->TexCoords        = tex_coords[i];
			s_BatchData.QuadBufferPtr->TexIndex         = texture_index;
			s_BatchData.QuadBufferPtr->TilingFactor     = tilingFactor;
			s_BatchData.QuadBufferPtr++;
		}

		s_BatchData.IndexCount += 6;
		s_BatchData.RenderingStatus.QuadCount++;
    }

    void Renderer2D::DrawQuad(const Mat4& transform, const Vec4& color)
    {
        DrawQuad(transform, s_BatchData.PlainTexture, color, 1.0f);
    }

    void Renderer2D::DrawQuad(const Mat4 & transform, const Ref<Texture2D>& texture, const Vec4 & tint, Float tilingFactor)
    {
        if (s_BatchData.IndexCount >= MAX_INDICES || s_BatchData.TextureSlotIndex >= MAX_TEXTURE_SLOTS) {
            Restart();
        }

        Float texture_index = 0.0f;
        for (uint32_t i = 1; i < s_BatchData.TextureSlotIndex; i++) 
        {
            if (s_BatchData.TextureSlots[i] == texture) 
            {
                texture_index = static_cast<Float>(i);
                break;
            }
        }

        if (texture_index == 0.0f) 
        {
            texture_index = static_cast<Float>(s_BatchData.TextureSlotIndex);
            s_BatchData.TextureSlots[s_BatchData.TextureSlotIndex] = texture;
            s_BatchData.TextureSlotIndex++;
        }

        for (UInt32 i = 0; i < MAX_QUAD_VERTEX_COUNT; i++) 
        {
            s_BatchData.QuadBufferPtr->Position         = transform * s_BatchData.QuadVertexPositions[i];
            s_BatchData.QuadBufferPtr->Color            = tint;
            s_BatchData.QuadBufferPtr->TexCoords        = DEFAULT_TEX_COORDS[i];
            s_BatchData.QuadBufferPtr->TexIndex         = texture_index;
            s_BatchData.QuadBufferPtr->TilingFactor     = tilingFactor;
            s_BatchData.QuadBufferPtr++;
        }

        s_BatchData.IndexCount += 6;
        s_BatchData.RenderingStatus.QuadCount++;
    }

    void Renderer2D::DrawQuad(const Mat4& transform, const Ref<SubTexture2D>& texture, const Vec4& tint, Float tilingFactor)
    {
        if (s_BatchData.IndexCount >= MAX_INDICES || s_BatchData.TextureSlotIndex >= MAX_TEXTURE_SLOTS) 
        {
            Restart();
        }

        const glm::vec2* tex_coords = texture->GetTextureCoords();
        float texture_index = 0.0f;

        for (uint32_t i = 1; i < s_BatchData.TextureSlotIndex; i++) 
        {
            if (s_BatchData.TextureSlots[i] == texture->GetTexturePtr()) 
            {
                texture_index = static_cast<float>(i);
                break;
            }
        }

        if (texture_index == 0.0f) 
        {
            texture_index = static_cast<float>(s_BatchData.TextureSlotIndex);
            s_BatchData.TextureSlots[s_BatchData.TextureSlotIndex] = texture->GetTexturePtr();
            s_BatchData.TextureSlotIndex++;
        }


        for (uint32_t i = 0; i < MAX_QUAD_VERTEX_COUNT; i++) 
        {
            s_BatchData.QuadBufferPtr->Position             = transform * s_BatchData.QuadVertexPositions[i];
            s_BatchData.QuadBufferPtr->Color                = tint;
            s_BatchData.QuadBufferPtr->TexCoords            = tex_coords[i];
            s_BatchData.QuadBufferPtr->TexIndex             = texture_index;
            s_BatchData.QuadBufferPtr->TilingFactor         = tilingFactor;
            s_BatchData.QuadBufferPtr++;
        }

        s_BatchData.IndexCount += 6;
        s_BatchData.RenderingStatus.QuadCount++;
    }

    const Renderer2D::Status& Renderer2D::RenderingStatus()
    {
        return s_BatchData.RenderingStatus;
    }

    void Renderer2D::StatusReset()
    {
        s_BatchData.RenderingStatus.DrawCount = TE_NULL;
        s_BatchData.RenderingStatus.QuadCount = TE_NULL;
    }
}