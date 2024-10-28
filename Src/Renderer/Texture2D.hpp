#pragma once

#include "TypeDef.hpp"

namespace TE::Renderer
{
    class Texture2D
    {
        public:
            Texture2D() = default;
            virtual ~Texture2D() = default;

            virtual void Bind(UInt32 slot = TE_NULL) const = TE_NULL;
            virtual void Unbind() const = TE_NULL;
            virtual TextureID GetID() const = TE_NULL;
            virtual Int32 GetWidth() const = TE_NULL;
            virtual Int32 GetHeight() const = TE_NULL;
            virtual Int32 GetChannels() const = TE_NULL;
            virtual UInt32 GetInternalFormat() const = TE_NULL;
            virtual UInt32 GetDataFormat() const = TE_NULL;
            virtual TextureData GetTextureData() const = TE_NULL;
    };

    class SubTexture2D
    {
        public:
            SubTexture2D() = default;
            virtual ~SubTexture2D() = default;

            virtual const Ref<Texture2D>& GetTexturePtr() const = TE_NULL;
            virtual const Vec2* GetTextureCoords() const = TE_NULL;
            virtual UInt32 GetInternalFormat() const = TE_NULL;
            virtual UInt32 GetDataFormat() const = TE_NULL;
    };

    Ref<Texture2D> CreateTexture2D(Int32 width, Int32 height);
    Ref<Texture2D> CreateTexture2D(const Path& path, Boolean flip = true);
    Ref<SubTexture2D> CreateSubTexture2D(const Ref<Texture2D>& texture, const Vec2& coords, const Vec2& cellSize, const Vec2& spriteSize);

}