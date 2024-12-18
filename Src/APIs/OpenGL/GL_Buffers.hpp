#pragma once

#include <glad/glad.h>

#include "TypeDef.hpp"
#include "Buffers.hpp"

namespace TE::APIs::OpenGL
{
    class GL_VertexBuffer : public TE::Renderer::VertexBuffer
    {
        public:
            GL_VertexBuffer() = default;
            GL_VertexBuffer(UInt32 allocatorSize);
            GL_VertexBuffer(VertexBufferData data, UInt32 dataSize);
            virtual ~GL_VertexBuffer();

            virtual void Bind() const override;
            virtual void Unbind() const override;
            virtual VertexBufferID GetID() const override { return m_VertexBufferID; }
            virtual void SetData(const void* data, UInt32 size) override;
            virtual void SetLayout(const TE::Renderer::BufferLayout& layout) override;
            virtual const TE::Renderer::BufferLayout& GetLayout() const override { return m_Layout; }

        private:
            VertexBufferID m_VertexBufferID{TE_NULL};
            TE::Renderer::BufferLayout m_Layout;
    };

    class GL_IndexBuffer : public TE::Renderer::IndexBuffer
    {
        public:
            GL_IndexBuffer() = default;
            GL_IndexBuffer(IndexBufferData data, UInt32 indicesCount);
            virtual ~GL_IndexBuffer();

            virtual void Bind() const override;
            virtual void Unbind() const override;
            virtual IndexBufferID GetID() const override { return m_IndexBufferID; }
            virtual UInt32 GetCount() const override { return m_Count; }

        private:
            IndexBufferID m_IndexBufferID{TE_NULL};
            UInt32 m_Count{TE_NULL};
    };
}