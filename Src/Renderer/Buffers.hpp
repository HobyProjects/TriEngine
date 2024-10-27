#pragma once

#include <string>
#include <vector>
#include <initializer_list>

#include "TypeDef.hpp"

namespace TE::Renderer
{
    enum class BufferComponents 
    {
        X       = 1,    
        XY      = 2,    
        UV      = 2,    
        XYZ     = 3,    
        RGB     = 3,    
        RGBA    = 4,    
        XYZW    = 4,    
        MAT3    = 3,    
        MAT4    = 4,    
    };

    enum class BufferStride 
    {
        BOOLEAN     = sizeof(Boolean),          
        F1          = sizeof(Float),            
        F2          = sizeof(Float) * 2,        
        F3          = sizeof(Float) * 3,        
        F4          = sizeof(Float) * 4,        
        MAT3        = sizeof(Float) * 3 * 3,    
        MAT4        = sizeof(Float) * 4 * 4,    
    };

    struct BufferElements 
    {
        Int32 Offset{TE_NULL};              
        String Name{};                      
        BufferStride Stride{};             
        Boolean Normalized{TE_FALSE};       
        BufferComponents Components{};     


        BufferElements() = default;
        BufferElements(const String& name, BufferComponents components, BufferStride stride, Boolean normalized) : Name(name), Components(components), Stride(stride), Normalized(normalized) {}
        ~BufferElements() = default;
    };

    class BufferLayout 
    {
        public:
            BufferLayout() = default;
            BufferLayout(std::initializer_list<BufferElements> elements) : m_Elements(elements) { CalStride(); }
            ~BufferLayout() = default;


            UInt32 GetStride() const { return m_Stride; }

            const std::vector<BufferElements>& GetElements() const { return m_Elements; }
            std::vector<BufferElements>::iterator begin() { return m_Elements.begin(); }
            std::vector<BufferElements>::iterator end() { return m_Elements.end(); }
            std::vector<BufferElements>::const_iterator begin() const { return m_Elements.begin(); }
            std::vector<BufferElements>::const_iterator end() const { return m_Elements.end(); }

        private:
            void CalStride()
            {
                m_Stride        = TE_NULL;
                UInt32 offset    = TE_NULL;

                for(auto& element : m_Elements)
                {
                    element.Offset = offset;
                    m_Stride += static_cast<UInt32>(element.Stride);
                    offset += static_cast<UInt32>(element.Stride);
                }
            }
        
        private:
            std::vector<BufferElements> m_Elements{};
            UInt32 m_Stride{TE_NULL};
    };

    class IVertexBuffer
    {
        public:
            IVertexBuffer() = default;
            ~IVertexBuffer() = default;

            virtual void Bind() const = TE_NULL;
            virtual void Unbind() const = TE_NULL;
            virtual VertexBufferID GetID() const = TE_NULL;

            virtual void SetData(const void* data, UInt32 size) = TE_NULL;
            virtual void SetLayout(const BufferLayout& layout) = TE_NULL;
            virtual const BufferLayout& GetLayout() const = TE_NULL;
    };

    class IIndexBuffer
    {
        public:
            IIndexBuffer() = default;
            ~IIndexBuffer() = default;

            virtual void Bind() const = TE_NULL;
            virtual void Unbind() const = TE_NULL;
            virtual IndexBufferID GetID() const = TE_NULL;
            virtual UInt32 GetCount() const = TE_NULL;
    };

    Ref<IVertexBuffer> CreateVertexBuffer(UInt32 allocatorSize);
    Ref<IVertexBuffer> CreateVertexBuffer(VertexBufferData data, UInt32 size);
    Ref<IIndexBuffer> CreateIndexBuffer(IndexBufferData data, UInt32 count);

}