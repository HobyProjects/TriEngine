#pragma once

#include <glad/glad.h>
#include "Texture2D.hpp"

namespace TE::APIs::OpenGL
{
    /**
     * @class GL_Texture2D
     *
     * @brief A class to represent an OpenGL 2D texture
     *
     * This class is used to represent an OpenGL 2D texture. It provides
     * functions to bind and unbind the texture, get the ID of the texture, and
     * get the width and height of the texture.
     */
    class GL_Texture2D : public TE::Renderer::Texture2D
    {
        public:
            /**
             * @brief Constructor for creating a blank OpenGL 2D texture
             *
             * @param width The width of the texture
             * @param height The height of the texture
             */
            GL_Texture2D(UInt32 width, UInt32 height);

            /**
             * @brief Constructor for creating an OpenGL 2D texture from a file
             *
             * @param path The path to the file containing the texture data
             * @param flip Whether to flip the texture data vertically
             */
            GL_Texture2D(const Path& path, bool flip = true);

            /**
             * @brief Destructor for the OpenGL 2D texture
             */
            ~GL_Texture2D();

            /**
             * @brief Binds the texture to the specified slot
             *
             * This function takes an optional parameter, which is the slot
             * number to bind the texture to. If the parameter is omitted, the
             * texture is bound to slot 0.
             *
             * @param slot The slot number to bind the texture to
             */
            virtual void Bind(UInt32 slot = 0) const override;

            /**
             * @brief Unbinds the texture
             *
             * This function unbinds the texture from the current slot.
             */
            virtual void Unbind() const override;

            /**
             * @brief Gets the ID of the texture
             *
             * This function returns the ID of the texture.
             *
             * @return The ID of the texture
             */
            virtual TextureID GetID() const override { return m_TextureID; }

            /**
             * @brief Gets the width of the texture
             *
             * This function returns the width of the texture in pixels.
             *
             * @return The width of the texture
             */
            virtual Int32 GetWidth() const override { return m_Width; }

            /**
             * @brief Gets the height of the texture
             *
             * This function returns the height of the texture in pixels.
             *
             * @return The height of the texture
             */
            virtual Int32 GetHeight() const override { return m_Height; }

            /**
             * @brief Gets the number of color channels in the texture
             *
             * This function returns the number of color channels in the texture.
             * For example, if the texture is an RGB image, this function will
             * return 3, indicating that the image has 3 color channels (red,
             * green, and blue). If the texture is an RGBA image, this function
             * will return 4, indicating that the image has 4 color channels (red,
             * green, blue, and alpha).
             *
             * @return The number of color channels in the texture
             */
            virtual Int32 GetChannels() const override { return m_Channels; }

            /**
             * @brief Gets the internal format of the texture
             *
             * This function returns the internal format of the texture. The
             * internal format is the format of the texture data stored in the
             * texture object. For example, if the internal format is
             * GL_RGBA8, then the texture data is stored as 8-bit unsigned
             * integers in the red, green, blue, and alpha channels.
             *
             * @return The internal format of the texture
             */
            virtual UInt32 GetInternalFormat() const override { return m_InternalFormat; }

            /**
             * @brief Gets the data format of the texture
             *
             * This function returns the data format of the texture. The data
             * format is the format of the texture data stored in memory. For
             * example, if the data format is GL_RGBA, then the texture data is
             * stored as 8-bit unsigned integers in the red, green, blue, and
             * alpha channels.
             *
             * @return The data format of the texture
             */
            virtual UInt32 GetDataFormat() const override { return m_DataFormat; }

            /**
             * @brief Gets the raw texture data
             *
             * This function returns a pointer to the raw texture data. The
             * texture data is stored in memory as a contiguous block of
             * unsigned bytes. The size of the block depends on the size of the
             * texture and the data format of the texture.
             *
             * @return A pointer to the raw texture data
             */
            virtual void* GetTextureData() const override { return m_Data; }

        private:

            Int32 m_Width{0};              /// The width of the texture in pixels
            Int32 m_Height{0};             /// The height of the texture in pixels
            Int32 m_Channels{0};           /// The number of color channels in the texture (e.g., 3 for RGB, 4 for RGBA)
            void* m_Data{nullptr};          /// A pointer to the raw texture data
            TextureID m_TextureID{0};       /// The OpenGL ID of the texture
            bool m_FromImageFile{false};    /// A flag indicating whether the texture was created from an image file
            UInt32 m_InternalFormat{0};     /// The internal format of the texture (e.g., GL_RGBA8)
            UInt32 m_DataFormat{0};         /// The format of the texture data (e.g., GL_RGBA)
    };

    /**
     * @class GL_SubTexture2D
     *
     * @brief A class to represent an OpenGL subtexture 2D
     *
     * This class is used to represent an OpenGL subtexture 2D. It provides
     * functions to bind and unbind the subtexture, get the ID of the subtexture,
     * and get the texture coordinates of the subtexture. The subtexture is
     * created from a shared_ptr to a Texture2D and a minimum and maximum set of
     * texture coordinates.
     */
    class GL_SubTexture2D : public TE::Renderer::SubTexture2D
    {
        public:
            /**
             * @brief Constructor to create a GL_SubTexture2D object
             *
             * This constructor creates a GL_SubTexture2D object from a
             * shared_ptr to a Texture2D and a minimum and maximum set of
             * texture coordinates.
             *
             * @param texture A shared_ptr to a Texture2D object, which is
             *                 the texture that this subtexture is a part of.
             * @param min     A Vec2 object representing the minimum set of
             *                 texture coordinates (s, t) for this subtexture.
             * @param max     A Vec2 object representing the maximum set of
             *                 texture coordinates (s, t) for this subtexture.
             */
            GL_SubTexture2D(const std::shared_ptr<TE::Renderer::Texture2D>& texture, const Vec2& min, const Vec2& max);

            /**
             * @brief Destructor to destroy a GL_SubTexture2D object
             *
             * This destructor is declared as = default, which means that it
             * will be generated automatically by the compiler. The generated
             * destructor will do nothing, since this class has no resources
             * that need to be cleaned up.
             */
            ~GL_SubTexture2D() = default;

            /**
             * @brief Gets a shared_ptr to the Texture2D object that this
             *        subtexture is a part of.
             *
             * This function returns a shared_ptr to the Texture2D object
             * that this subtexture is a part of. The shared_ptr is
             * const, so it can't be used to modify the object it points to.
             *
             * @return A shared_ptr to the Texture2D object that this
             *         subtexture is a part of.
             */
            virtual const std::shared_ptr<TE::Renderer::Texture2D>& GetTexturePtr() const override
            {
                return m_Texture;
            }

            /**
             * @brief Gets the texture coordinates of this subtexture.
             *
             * This function returns an array of 4 Vec2 objects, which
             * represent the minimum and maximum texture coordinates (s, t)
             * for this subtexture. The array is laid out as follows:
             *
             *   m_TexCoords[0] = (s_min, t_min)
             *   m_TexCoords[1] = (s_min, t_max)
             *   m_TexCoords[2] = (s_max, t_min)
             *   m_TexCoords[3] = (s_max, t_max)
             *
             * @return An array of 4 Vec2 objects, which represent the
             *         minimum and maximum texture coordinates (s, t) for
             *         this subtexture.
             */
            virtual const Vec2* GetTextureCoords() const override
            {
                return m_TexCoords;
            }

            /**
             * @brief Gets the internal format of the texture that this
             *        subtexture is a part of.
             *
             * This function returns the internal format of the texture
             * that this subtexture is a part of. The internal format is
             * the format of the texture data stored in the texture object.
             * For example, if the internal format is GL_RGBA8, then the
             * texture data is stored as 8-bit unsigned integers in the
             * red, green, blue, and alpha channels.
             *
             * @return The internal format of the texture that this
             *         subtexture is a part of.
             */
            virtual UInt32 GetInternalFormat() const override
            {
                return m_InternalFormat;
            }

            /**
             * @brief Gets the data format of the texture that this
             *        subtexture is a part of.
             *
             * This function returns the data format of the texture that
             * this subtexture is a part of. The data format is the format
             * of the texture data stored in memory. For example, if the
             * data format is GL_RGBA, then the texture data is stored as
             * 8-bit unsigned integers in the red, green, blue, and alpha
             * channels.
             *
             * @return The data format of the texture that this subtexture
             *         is a part of.
             */
            virtual UInt32 GetDataFormat() const override
            {
                return m_DataFormat;
            }

        private:
            /**
             * @brief The number of texture coordinates in the array
             *
             * The number of texture coordinates in the array is 4, which
             * represents the minimum and maximum texture coordinates (s, t)
             * for this subtexture. The array is laid out as follows:
             *
             *   m_TexCoords[0] = (s_min, t_min)
             *   m_TexCoords[1] = (s_min, t_max)
             *   m_TexCoords[2] = (s_max, t_min)
             *   m_TexCoords[3] = (s_max, t_max)
             */
            static const UInt32 NUMBER_OF_TEXTURE_COORDS = 4;

            /**
             * @brief A shared_ptr to the Texture2D object that this
             *        subtexture is a part of.
             *
             * This shared_ptr is used to store a pointer to the Texture2D
             * object that this subtexture is a part of. The shared_ptr is
             * const, so it can't be used to modify the object it points to.
             */
            std::shared_ptr<TE::Renderer::Texture2D> m_Texture;

            /**
             * @brief An array of 4 Vec2 objects, which represent the
             *        minimum and maximum texture coordinates (s, t) for
             *        this subtexture.
             *
             * The array is laid out as follows:
             *
             *   m_TexCoords[0] = (s_min, t_min)
             *   m_TexCoords[1] = (s_min, t_max)
             *   m_TexCoords[2] = (s_max, t_min)
             *   m_TexCoords[3] = (s_max, t_max)
             */
            Vec2 m_TexCoords[NUMBER_OF_TEXTURE_COORDS];

            /**
             * @brief The internal format of the texture that this
             *        subtexture is a part of.
             *
             * The internal format is the format of the texture data stored
             * in the texture object. For example, if the internal format
             * is GL_RGBA8, then the texture data is stored as 8-bit unsigned
             * integers in the red, green, blue, and alpha channels.
             */
            UInt32 m_InternalFormat{0};

            /**
             * @brief The data format of the texture that this subtexture
             *        is a part of.
             *
             * The data format is the format of the texture data stored in
             * memory. For example, if the data format is GL_RGBA, then the
             * texture data is stored as 8-bit unsigned integers in the red,
             * green, blue, and alpha channels.
             */
            UInt32 m_DataFormat{0};
    };
}