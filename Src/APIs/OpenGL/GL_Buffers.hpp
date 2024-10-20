#pragma once

#include <glad/glad.h>

#include "TypeDef.hpp"
#include "Buffers.hpp"

namespace TE::APIs::OpenGL
{
    /**
     * @class GL_VertexBuffer
     *
     * @brief A class that represents an OpenGL vertex buffer
     *
     * This class is an interface to represent an OpenGL vertex buffer. It
     * provides functions to bind and unbind the vertex buffer, as well as to
     * get the ID of the vertex buffer. Additionally, it provides a function
     * to set the data of the vertex buffer and a function to set the layout
     * of the vertex buffer.
     */
    class GL_VertexBuffer : public TE::Renderer::VertexBuffer
    {
        public:
            /**
             * @brief Default constructor
             *
             * This function is the default constructor for the GL_VertexBuffer
             * class. It creates an empty vertex buffer.
             */
            GL_VertexBuffer() = default;

            /**
             * @brief Constructor to create a vertex buffer with the specified size
             *
             * @param size The size of the vertex buffer in bytes
             *
             * This function creates a vertex buffer with the specified size.
             */
            GL_VertexBuffer(uint32_t allocatorSize);

            /**
             * @brief Constructor to create a vertex buffer with the specified data
             *
             * @param data The data to store in the vertex buffer
             * @param dataSize The size of the data in bytes
             *
             * This function creates a vertex buffer and stores the specified
             * data in it.
             */
            GL_VertexBuffer(VertexBufferData data, uint32_t dataSize);

            /**
             * @brief Destructor
             *
             * This function is the destructor for the GL_VertexBuffer class.
             */
            virtual ~GL_VertexBuffer();

            /**
             * @brief Bind the vertex buffer
             *
             * This function binds the vertex buffer for rendering. It must
             * be overridden in the derived classes.
             */
            virtual void Bind() const override;

            /**
             * @brief Unbind the vertex buffer
             *
             * This function unbinds the vertex buffer for rendering. It must
             * be overridden in the derived classes.
             */
            virtual void Unbind() const override;

            /**
             * @brief Get the ID of the vertex buffer
             *
             * This function returns the ID of the vertex buffer. It must
             * be overridden in the derived classes.
             */
            virtual VertexBufferID GetID() const override { return m_VertexBufferID; }

            /**
             * @brief Set the data of the vertex buffer
             *
             * @param data The data to store in the vertex buffer
             * @param size The size of the data in bytes
             *
             * This function sets the data of the vertex buffer.
             */
            virtual void SetData(const void* data, uint32_t size) override;

            /**
             * @brief Set the layout of the vertex buffer
             *
             * @param layout The layout of the vertex buffer
             *
             * This function sets the layout of the vertex buffer.
             */
            virtual void SetLayout(const TE::Renderer::BufferLayout& layout) override;

            /**
             * @brief Get the layout of the vertex buffer
             *
             * This function returns the layout of the vertex buffer.
             */
            virtual const TE::Renderer::BufferLayout& GetLayout() const override { return m_Layout; }

        private:

            /**
             * @brief The ID of the vertex buffer
             *
             * This is the OpenGL ID of the vertex buffer. It is used to
             * identify the vertex buffer in OpenGL.
             */
            VertexBufferID m_VertexBufferID{0};

            /**
             * @brief The layout of the vertex buffer
             *
             * This is the layout of the vertex buffer. It describes the
             * structure of the data stored in the vertex buffer.
             */
            TE::Renderer::BufferLayout m_Layout;
    };

    /**
     * @class GL_IndexBuffer
     *
     * @brief A class to represent an OpenGL index buffer
     *
     * This class is used to represent an OpenGL index buffer. It provides
     * functions to bind and unbind the index buffer, as well as to get the
     * ID of the index buffer.
     */
    class GL_IndexBuffer : public TE::Renderer::IndexBuffer
    {
        public:
            /**
             * @brief Default constructor
             *
             * This function is the default constructor for the GL_IndexBuffer
             * class.
             */
            GL_IndexBuffer() = default;

            /**
             * @brief Constructor
             *
             * This function is the constructor for the GL_IndexBuffer class.
             * It creates an OpenGL index buffer from the given data.
             *
             * @param data The data to store in the index buffer
             * @param indicesCount The number of indices in the index buffer
             */
            GL_IndexBuffer(IndexBufferData data, uint32_t indicesCount);

            /**
             * @brief Destructor
             *
             * This function is the destructor for the GL_IndexBuffer class.
             */
            virtual ~GL_IndexBuffer();

            /**
             * @brief Bind the index buffer
             *
             * This function binds the index buffer for rendering. It must
             * be overridden in the derived classes.
             */
            virtual void Bind() const override;

            /**
             * @brief Unbind the index buffer
             *
             * This function unbinds the index buffer for rendering. It must
             * be overridden in the derived classes.
             */
            virtual void Unbind() const override;

            /**
             * @brief Get the ID of the index buffer
             *
             * This function returns the ID of the index buffer. It must
             * be overridden in the derived classes.
             */
            virtual IndexBufferID GetID() const override { return m_IndexBufferID; }

            /**
             * @brief Get the number of indices in the index buffer
             *
             * This function returns the number of indices in the index
             * buffer.
             */
            uint32_t GetCount() const { return m_Count; }

        private:

            /**
             * @brief The ID of the index buffer
             *
             * This is the OpenGL ID of the index buffer. It is used to
             * identify the index buffer in OpenGL.
             */
            IndexBufferID m_IndexBufferID{0};

            /**
             * @brief The number of indices in the index buffer
             *
             * This is the number of indices in the index buffer. It is
             * used to determine the size of the index buffer.
             */
            uint32_t m_Count{0};
    };
}