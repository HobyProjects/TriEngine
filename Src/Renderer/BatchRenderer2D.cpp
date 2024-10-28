#include "BatchRenderer2D.hpp"

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
        uint32_t TextureSlotIndex{ 1 };

        BatchRenderer2D::Status RenderingStatus;
        Vec4 QuadVertexPositions[MAX_QUAD_VERTEX_COUNT];

    }; static BatchData s_BatchData;

    void BatchRenderer2D::Restart() 
    {
        End();
        s_BatchData.QuadBufferPtr = s_BatchData.QuadBuffer;
        s_BatchData.IndexCount = 0;
        s_BatchData.TextureSlotIndex = 1;
    }

    void BatchRenderer2D::Init()
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

                for(uint32_t i = 0; i < MAX_TEXTURE_SLOTS; i++)
                    s_BatchData.TextureSlots[i] = nullptr;

                s_BatchData.PlainTexture = CreateTexture2D(1, 1);
                s_BatchData.TextureSlots[0] = s_BatchData.PlainTexture;
            }
        }
    }
}