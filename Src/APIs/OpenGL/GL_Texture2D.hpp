#pragma once

#include <glad/glad.h>
#include "Texture2D.hpp"

namespace TE::APIs::OpenGL
{
    class GL_Texture2D : public TE::Renderer::Texture2D
    {
        public:
            GL_Texture2D(UInt32 width, UInt32 height);
            GL_Texture2D(const Path& path, Boolean flip = true);
            virtual ~GL_Texture2D();

            virtual void Bind(UInt32 slot = TE_NULL) const override;
            virtual void Unbind() const override;
            virtual TextureID GetID() const override { return m_TextureID; }
            virtual Int32 GetWidth() const override { return m_Width; }
            virtual Int32 GetHeight() const override { return m_Height; }
            virtual Int32 GetChannels() const override { return m_Channels; }
            virtual UInt32 GetInternalFormat() const override { return m_InternalFormat; }
            virtual UInt32 GetDataFormat() const override { return m_DataFormat; }
            virtual TextureData GetTextureData() const override { return m_Data; }

        private:

            Int32 m_Width{TE_NULL};              
            Int32 m_Height{TE_NULL};             
            Int32 m_Channels{TE_NULL};           
            TextureData m_Data{nullptr};          
            TextureID m_TextureID{TE_NULL};       
            Boolean m_FromImageFile{TE_FALSE};    
            UInt32 m_InternalFormat{TE_NULL};     
            UInt32 m_DataFormat{TE_NULL};         
    };

    class GL_SubTexture2D : public TE::Renderer::SubTexture2D
    {
        public:
            GL_SubTexture2D(const Ref<TE::Renderer::Texture2D>& texture, const Vec2& min, const Vec2& max);
            ~GL_SubTexture2D() = default;

            virtual const Ref<TE::Renderer::Texture2D>& GetTexturePtr() const override
            {
                return m_Texture;
            }

            virtual const Vec2* GetTextureCoords() const override
            {
                return m_TexCoords;
            }

            virtual UInt32 GetInternalFormat() const override
            {
                return m_InternalFormat;
            }

            virtual UInt32 GetDataFormat() const override
            {
                return m_DataFormat;
            }

        private:
            static const UInt32 NUMBER_OF_TEXTURE_COORDS = 4;
            std::shared_ptr<TE::Renderer::Texture2D> m_Texture;
            Vec2 m_TexCoords[NUMBER_OF_TEXTURE_COORDS];
            UInt32 m_InternalFormat{TE_NULL};
            UInt32 m_DataFormat{TE_NULL};
    };
}