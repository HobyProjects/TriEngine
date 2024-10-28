#pragma once

#include <memory>
#include "Buffers.hpp"
#include "TypeDef.hpp"

namespace TE::Renderer
{
    class VertexArray
    {
        public:
            VertexArray() = default;
            virtual ~VertexArray() = default;

            virtual void Bind() const = TE_NULL;
            virtual void Unbind() const = TE_NULL;
            virtual VertexArrayID GetID() const = TE_NULL;
            virtual void EmplaceVtxBuffer(const Ref<VertexBuffer>& vtxBuffer) = TE_NULL;
            virtual void EmplaceIdxBuffer(const Ref<IndexBuffer>& idxBuffer) = TE_NULL;
            virtual const std::vector<Ref<VertexBuffer>>& GetVtxBuffers() const = TE_NULL;
            virtual const Ref<IndexBuffer>& GetIdexBuffer() const = TE_NULL;
    };
    
    Ref<VertexArray> CreateVertexArray();
}