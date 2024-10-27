#pragma once

#include <glad/glad.h>
#include "VertexArray.hpp"

namespace TE::APIs::OpenGL
{
    class GL_VertexArray : public TE::Renderer::IVertexArray
    {
        public:
            GL_VertexArray();
            virtual ~GL_VertexArray();

            virtual void Bind() const override;
            virtual void Unbind() const override;
            virtual VertexArrayID GetID() const override;
            virtual void EmplaceVtxBuffer(const Ref<TE::Renderer::IVertexBuffer>& vtxBuffer) override;
            virtual void EmplaceIdxBuffer(const Ref<TE::Renderer::IIndexBuffer>& idxBuffer) override;
            virtual const std::vector<Ref<TE::Renderer::IVertexBuffer>>& GetVtxBuffers() const override;
            virtual const Ref<TE::Renderer::IIndexBuffer>& GetIdexBuffer() const override;

        private:
            VertexArrayID m_VertexArrayID = 0;
            std::vector<Ref<TE::Renderer::IVertexBuffer>> m_VtxBuffers;
            Ref<TE::Renderer::IIndexBuffer> m_IdexBuffer;
    };
}