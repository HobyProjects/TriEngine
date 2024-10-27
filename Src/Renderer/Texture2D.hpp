#pragma once

#include "TypeDef.hpp"

namespace TE::Renderer
{
    class ITexture2D
    {
        public:
            ITexture2D() = default;
            virtual ~ITexture2D() = default;

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

    class ISubTexture2D
    {
        public:
            ISubTexture2D() = default;
            virtual ~ISubTexture2D() = default;

            virtual const std::shared_ptr<ITexture2D>& GetTexturePtr() const = TE_NULL;
            virtual const Vec2* GetTextureCoords() const = TE_NULL;
            virtual UInt32 GetInternalFormat() const = TE_NULL;
            virtual UInt32 GetDataFormat() const = TE_NULL;
    };

    Ref<ITexture2D> CreateTexture2D(Int32 width, Int32 height);
    Ref<ITexture2D> CreateTexture2D(const Path& path, Boolean flip = true);
    Ref<ISubTexture2D> CreateSubTexture2D(const Ref<ITexture2D>& texture, const Vec2& coords, const Vec2& cellSize, const Vec2& spriteSize);

}