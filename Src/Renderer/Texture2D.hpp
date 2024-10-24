#pragma once

#include "TypeDef.hpp"

namespace TE::Renderer
{
    /**
     * @class Texture2D
     *
     * @brief A class that represents a 2D texture
     *
     * This class is used to represent a 2D texture. It provides functions to
     * bind and unbind the texture, as well as to get the ID, width, height, and
     * internal format of the texture.
     */
    class Texture2D
    {
        public:
            Texture2D() = default;
            virtual ~Texture2D() = default;

            /**
             * @brief Bind the texture to a specified slot
             *
             * This function binds the texture to a specified slot. If no slot
             * is specified, the texture is bound to slot 0.
             *
             * @param slot The slot to bind the texture to
             */
            virtual void Bind(UInt32 slot = 0) const = 0;

            /**
             * @brief Unbind the texture
             *
             * This function unbinds the texture.
             */
            virtual void Unbind() const = 0;

            /**
             * @brief Get the ID of the texture
             *
             * This function returns the ID of the texture.
             *
             * @return The ID of the texture
             */
            virtual TextureID GetID() const = 0;

            /**
             * @brief Get the width of the texture
             *
             * This function returns the width of the texture.
             *
             * @return The width of the texture
             */
            virtual UInt32 GetWidth() const = 0;

            /**
             * @brief Get the height of the texture
             *
             * This function returns the height of the texture.
             *
             * @return The height of the texture
             */
            virtual UInt32 GetHeight() const = 0;

            /**
             * @brief Get the number of channels in the texture
             *
             * This function returns the number of channels in the texture.
             *
             * @return The number of channels in the texture
             */
            virtual UInt32 GetChannels() const = 0;

            /**
             * @brief Get the internal format of the texture
             *
             * This function returns the internal format of the texture.
             *
             * @return The internal format of the texture
             */
            virtual UInt32 GetInternalFormat() const = 0;

            /**
             * @brief Get the data format of the texture
             *
             * This function returns the data format of the texture.
             *
             * @return The data format of the texture
             */
            virtual UInt32 GetDataFormat() const = 0;

            /**
             * @brief Get the texture data
             *
             * This function returns the texture data.
             *
             * @return The texture data
             */
            virtual TextureData GetTextureData() const = 0;
    };

    /**
     * @class SubTexture2D
     *
     * @brief A class that represents a subtexture of a 2D texture
     *
     * This class is used to represent a subtexture of a 2D texture. It provides
     * functions to get the texture pointer, texture coordinates, internal format,
     * and data format.
     */
    class SubTexture2D
    {
        public:
            SubTexture2D() = default;
            virtual ~SubTexture2D() = default;

            /**
             * @brief Get the texture pointer
             *
             * This function returns a pointer to the texture.
             *
             * @return A pointer to the texture
             */
            virtual const std::shared_ptr<Texture2D>& GetTexturePtr() const = 0;

            /**
             * @brief Get the texture coordinates
             *
             * This function returns the texture coordinates of the subtexture.
             *
             * @return The texture coordinates of the subtexture
             */
            virtual const Vec2* GetTextureCoords() const = 0;

            /**
             * @brief Get the internal format of the subtexture
             *
             * This function returns the internal format of the subtexture.
             *
             * @return The internal format of the subtexture
             */
            virtual UInt32 GetInternalFormat() const = 0;

            /**
             * @brief Get the data format of the subtexture
             *
             * This function returns the data format of the subtexture.
             *
             * @return The data format of the subtexture
             */
            virtual UInt32 GetDataFormat() const = 0;
    };
}