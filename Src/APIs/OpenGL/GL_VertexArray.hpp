#pragma once

#include <glad/glad.h>
#include "VertexArray.hpp"

namespace TE::APIs::OpenGL
{
    class GL_VertexArray : public TE::Renderer::VertexArray
    {
        public:
            GL_VertexArray();
            virtual ~GL_VertexArray();

            virtual void Bind() const override;
            virtual void Unbind() const override;
            virtual VertexArrayID GetID() const override;
            virtual void EmplaceVtxBuffer(const Ref<TE::Renderer::VertexBuffer>& vtxBuffer) override;
            virtual void EmplaceIdxBuffer(const Ref<TE::Renderer::IndexBuffer>& idxBuffer) override;
            virtual const std::vector<Ref<TE::Renderer::VertexBuffer>>& GetVtxBuffers() const override;
            virtual const Ref<TE::Renderer::IndexBuffer>& GetIdexBuffer() const override;

        private:
            VertexArrayID m_VertexArrayID = 0;
            std::vector<Ref<TE::Renderer::VertexBuffer>> m_VtxBuffers;
            Ref<TE::Renderer::IndexBuffer> m_IdexBuffer;
    };
}