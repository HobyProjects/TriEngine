#pragma once

#include "TypeDef.hpp"

namespace TE::Renderer
{
    struct FrameBufferSpecifications 
    {
        UInt32 Width{TE_NULL};
        UInt32 Height{TE_NULL};

        Boolean SwapChainTarget{TE_FALSE};
    };

    class FrameBuffer
    {
        public:
            FrameBuffer() = default;
            virtual ~FrameBuffer() = default;

            virtual void Bind() const = TE_NULL;
            virtual void Unbind() const = TE_NULL;
            virtual void ResizeFrame(UInt32 width, UInt32 height) = TE_NULL;
            virtual FrameBufferID GetFrameBufferID() const = TE_NULL;
            virtual FrameBufferAttachmentID GetColorAttachment() const = TE_NULL;
            virtual FrameBufferSpecifications& GetFrameSpecification() = TE_NULL;

        protected:
            virtual void CreateFrame() = TE_NULL;
    };

    Ref<FrameBuffer> CreateFrameBuffer(const FrameBufferSpecifications& specification);
}