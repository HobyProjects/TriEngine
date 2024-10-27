#include "GL_VertexArray.hpp"
#include "Asserts.hpp"

namespace TE::APIs::OpenGL
{
    GL_VertexArray::GL_VertexArray()
    {
        glCreateVertexArrays(1, &m_VertexArrayID);
    }

    GL_VertexArray::~GL_VertexArray()
    {
        glDeleteVertexArrays(1, &m_VertexArrayID);
    }

    void GL_VertexArray::Bind() const
    {
        glBindVertexArray(m_VertexArrayID);
    }

    void GL_VertexArray::Unbind() const
    {
        glBindVertexArray(0);
    }

    VertexArrayID GL_VertexArray::GetID() const
    {
        return m_VertexArrayID;
    }

    static GLenum GetDataType(TE::Renderer::BufferStride component) 
    {
        switch (component) 
        {
            case TE::Renderer::BufferStride::F1: return GL_FLOAT;
            case TE::Renderer::BufferStride::F2: return GL_FLOAT;
            case TE::Renderer::BufferStride::F3: return GL_FLOAT;
            case TE::Renderer::BufferStride::F4: return GL_FLOAT;
            case TE::Renderer::BufferStride::MAT3: return GL_FLOAT;
            case TE::Renderer::BufferStride::MAT4: return GL_FLOAT;
            default: return 0;
        }

        TE_CORE_ERROR("Unknown component type");
        return -1;
    }

    void GL_VertexArray::EmplaceVtxBuffer(const Ref<TE::Renderer::IVertexBuffer>& vtxBuffer)
    {
        glBindVertexArray(m_VertexArrayID);
        vtxBuffer->Bind();
        const auto& layout = vtxBuffer->GetLayout();
        const auto& elements = layout.GetElements();
        UInt32 layout_index{ 0 };

        for (auto& element : elements) 
        {
            glEnableVertexAttribArray(layout_index);
            glVertexAttribPointer(
                layout_index,
                static_cast<GLint>(element.Components),
                GL_FLOAT,
                element.Normalized ? GL_TRUE : GL_FALSE,
                layout.GetStride(),
                (const void*)element.Offset
            );
        }

        m_VtxBuffers.emplace_back(vtxBuffer);
    }
    void GL_VertexArray::EmplaceIdxBuffer(const Ref<TE::Renderer::IIndexBuffer>& idxBuffer)
    {
        glBindVertexArray(m_VertexArrayID);
        m_IdexBuffer = idxBuffer;
        m_IdexBuffer->Bind();
    }

    const std::vector<Ref<TE::Renderer::IVertexBuffer>>& GL_VertexArray::GetVtxBuffers() const
    {
        return m_VtxBuffers;
    }
    
    const Ref<TE::Renderer::IIndexBuffer>& GL_VertexArray::GetIdexBuffer() const
    {
        return m_IdexBuffer;
    }
}