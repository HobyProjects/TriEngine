#pragma once

#include <memory>
#include "Buffers.hpp"
#include "TypeDef.hpp"

namespace TE::Renderer
{
    class IVertexArray
    {
        public:
            IVertexArray() = default;
            virtual ~IVertexArray() = default;

            virtual void Bind() const = TE_NULL;
            virtual void Unbind() const = TE_NULL;
            virtual VertexArrayID GetID() const = TE_NULL;
            virtual void EmplaceVtxBuffer(const Ref<IVertexBuffer>& vtxBuffer) = TE_NULL;
            virtual void EmplaceIdxBuffer(const Ref<IIndexBuffer>& idxBuffer) = TE_NULL;
            virtual const std::vector<Ref<IVertexBuffer>>& GetVtxBuffers() const = TE_NULL;
            virtual const Ref<IIndexBuffer>& GetIdexBuffer() const = TE_NULL;
    };
    
    Ref<IVertexArray> CreateVertexArray();
}