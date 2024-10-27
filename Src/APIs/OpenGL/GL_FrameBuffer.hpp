#pragma once

#include <glad/glad.h>

#include "TypeDef.hpp"
#include "FrameBuffer.hpp"

namespace TE::APIs::OpenGL
{
    class GL_FrameBuffer : public TE::Renderer::IFrameBuffer
    {
        public:
            GL_FrameBuffer() = default;
            GL_FrameBuffer(const TE::Renderer::FrameBufferSpecifications& specification);
            virtual ~GL_FrameBuffer();

            virtual void Bind() const override;
            virtual void Unbind() const override;
            virtual void ResizeFrame(UInt32 width, UInt32 height) override;
            virtual FrameBufferID GetFrameBufferID() const override;
            virtual FrameBufferAttachmentID GetColorAttachment() const override;
            virtual TE::Renderer::FrameBufferSpecifications& GetFrameSpecification() override;

        protected:
            virtual void CreateFrame() override;

        private:
            FrameBufferID m_FrameBufferID{TE_NULL};
            FrameBufferAttachmentID m_ColorAttachment{TE_NULL};
            FrameBufferAttachmentID m_DepthAttachment{TE_NULL};
            TE::Renderer::FrameBufferSpecifications m_Specification;
    };
}