#pragma once

#include <string>
#include <vector>
#include <initializer_list>

#include "TypeDef.hpp"

namespace TE::Renderer
{
    // Enum to represent different buffer components and their associated sizes
    enum class BufferComponents 
    {
        X       = 1,    // Single component (e.g., X coordinate)
        XY      = 2,    // Two components (e.g., X and Y coordinates)
        UV      = 2,    // Two components (e.g., texture coordinates U and V)
        XYZ     = 3,    // Three components (e.g., X, Y, and Z coordinates)
        RGB     = 3,    // Three components (e.g., Red, Green, and Blue color)
        RGBA    = 4,    // Four components (e.g., Red, Green, Blue, and Alpha color)
        XYZW    = 4,    // Four components (e.g., X, Y, Z, and W coordinates)
        MAT3    = 3,    // Three components per row (3x3 matrix)
        MAT4    = 4,    // Four components per row (4x4 matrix)
    };

    /**
     * @brief Enum to represent different buffer strides and their associated sizes
     */
    enum class BufferStride 
    {
        BOOLEAN     = sizeof(bool),             ///< Size of a boolean (1 byte)
        F1          = sizeof(float),            ///< Size of a single float (4 bytes)
        F2          = sizeof(float) * 2,        ///< Size of two floats (8 bytes)
        F3          = sizeof(float) * 3,        ///< Size of three floats (12 bytes)
        F4          = sizeof(float) * 4,        ///< Size of four floats (16 bytes)
        MAT3        = sizeof(float) * 3 * 3,    ///< Size of a 3x3 matrix (9 floats, 36 bytes)
        MAT4        = sizeof(float) * 4 * 4,    ///< Size of a 4x4 matrix (16 floats, 64 bytes)
    };

    /**
     * @brief Structure to represent a single element in a buffer layout
     *
     * A buffer element is a single component of a buffer, which can be a vertex
     * position, a texture coordinate, a color, or any other type of data that is
     * stored in a buffer.
     *
     * @var Offset The offset of the element in bytes from the beginning of the
     *             buffer
     * @var Name   The name of the element (e.g., "Position", "TexCoord", etc.)
     * @var Stride The size of the element in bytes
     * @var Normalized Whether the element is normalized when being read from the buffer
     * @var Components The type of the element (e.g., XYZW, RGBA, etc.)
     */
    struct BufferElements 
    {
        int32_t Offset{0};              /**< Offset of the element in bytes from the beginning of the buffer */
        std::string Name{};             /**< Name of the element (e.g., "Position", "TexCoord", etc.) */
        BufferStride Stride{};          /**< Size of the element in bytes */
        bool Normalized{false};         /**< Whether the element is normalized when being read from the buffer */
        BufferComponents Components{};  /**< Type of the element (e.g., XYZW, RGBA, etc.) */

        /**
         * @brief Constructor to create a buffer element
         *
         * @param name The name of the element
         * @param components The type of the element
         * @param stride The size of the element in bytes
         * @param normalized Whether the element is normalized when being read from the buffer
         */
        BufferElements() = default;
        BufferElements(const std::string& name, BufferComponents components, BufferStride stride, bool normalized) : 
                Name(name), Components(components), Stride(stride), Normalized(normalized) {}
        ~BufferElements() = default;
    };


    /**
     * @brief Class to represent a buffer layout
     *
     * A buffer layout is a description of the memory layout of a buffer. It is
     * used by the renderer to determine the size of each element in the buffer
     * and the offset of each element from the beginning of the buffer.
     */
    class BufferLayout 
    {
        public:
            /**
             * @brief Constructor to create a buffer layout
             *
             * @param elements A list of BufferElements that describe the layout
             *                  of the buffer
             */
            BufferLayout() = default;
            BufferLayout(std::initializer_list<BufferElements> elements) : m_Elements(elements) { CalStride(); }
            ~BufferLayout() = default;

            /**
             * @brief Get the stride of the buffer layout
             *
             * The stride is the size of the buffer in bytes. It is calculated
             * by summing the size of each element in the buffer.
             *
             * @return The stride of the buffer layout
             */
            uint32_t GetStride() const { return m_Stride; }

            /**
             * @brief Get the elements of the buffer layout
             *
             * The elements of the buffer layout are the individual components
             * of the buffer. Each element has a name, a type, and a size.
             *
             * @return A vector of BufferElements
             */
            const std::vector<BufferElements>& GetElements() const { return m_Elements; }

            /**
             * @brief Get an iterator to the beginning of the elements
             *
             * @return An iterator to the beginning of the elements
             */
            std::vector<BufferElements>::iterator begin() { return m_Elements.begin(); }

            /**
             * @brief Get an iterator to the end of the elements
             *
             * @return An iterator to the end of the elements
             */
            std::vector<BufferElements>::iterator end() { return m_Elements.end(); }

            /**
             * @brief Get a const iterator to the beginning of the elements
             *
             * @return A const iterator to the beginning of the elements
             */
            std::vector<BufferElements>::const_iterator begin() const { return m_Elements.begin(); }

            /**
             * @brief Get a const iterator to the end of the elements
             *
             * @return A const iterator to the end of the elements
             */
            std::vector<BufferElements>::const_iterator end() const { return m_Elements.end(); }

        private:
            /**
             * @brief Calculate the stride of the buffer layout
             *
             * The stride is the size of the buffer in bytes. It is calculated
             * by summing the size of each element in the buffer.
             */
            void CalStride()
            {
                m_Stride        = 0;
                int32_t offset  = 0;

                for(auto& element : m_Elements)
                {
                    element.Offset = offset;
                    m_Stride += static_cast<uint32_t>(element.Stride);
                    offset += static_cast<uint32_t>(element.Stride);
                }
            }
        
        private:
            /**
             * @brief A vector of elements that describe the buffer layout
             */
            std::vector<BufferElements> m_Elements{};

            /**
             * @brief The stride of the buffer in bytes
             *
             * The stride is the total size of the elements in the buffer in bytes.
             * It is calculated by summing the size of each element in the buffer.
             */
            uint32_t m_Stride{0};
    };

    /**
     * @brief A class to represent a vertex buffer
     *
     * Vertex buffers are used to store vertex data for rendering. This class
     * provides a common interface for vertex buffers.
     */
    class VertexBuffer
    {
        public:
            /**
             * @brief Constructor
             *
             * The constructor is left empty. There is no need to initialize
             * anything in the constructor.
             */
            VertexBuffer() = default;

            /**
             * @brief Destructor
             *
             * The destructor is left empty. There is no need to deallocate
             * anything in the destructor.
             */
            ~VertexBuffer() = default;

            /**
             * @brief Bind the vertex buffer
             *
             * This function binds the vertex buffer for rendering. It must
             * be overridden in the derived classes.
             */
            virtual void Bind() const = 0;

            /**
             * @brief Unbind the vertex buffer
             *
             * This function unbinds the vertex buffer for rendering. It must
             * be overridden in the derived classes.
             */
            virtual void Unbind() const = 0;

            /**
             * @brief Get the ID of the vertex buffer
             *
             * This function returns the ID of the vertex buffer. It must
             * be overridden in the derived classes.
             */
            virtual TE_VertexBufferID GetID() const = 0;

            /**
             * @brief Set the data of the vertex buffer
             *
             * This function sets the data of the vertex buffer. It must
             * be overridden in the derived classes.
             *
             * @param data The data to set
             * @param size The size of the data in bytes
             */
            virtual void SetData(const void* data, uint32_t size) = 0;

            /**
             * @brief Set the layout of the vertex buffer
             *
             * This function sets the layout of the vertex buffer. It must
             * be overridden in the derived classes.
             *
             * @param layout The layout of the vertex buffer
             */
            virtual void SetLayout(const BufferLayout& layout) = 0;

            /**
             * @brief Get the layout of the vertex buffer
             *
             * This function returns the layout of the vertex buffer. It must
             * be overridden in the derived classes.
             *
             * @return The layout of the vertex buffer
             */
            virtual const BufferLayout& GetLayout() const = 0;
    };

    /**
     * @class IndexBuffer
     *
     * @brief A class that represents an index buffer
     *
     * This class is an interface to represent an index buffer. It
     * provides functions to bind and unbind the index buffer, as well
     * as to get the ID of the index buffer.
     */
    class IndexBuffer
    {
        public:
            /**
             * @brief Default constructor
             *
             * This function is the default constructor for the IndexBuffer
             * class.
             */
            IndexBuffer() = default;

            /**
             * @brief Destructor
             *
             * This function is the destructor for the IndexBuffer class.
             */
            ~IndexBuffer() = default;

            /**
             * @brief Bind the index buffer
             *
             * This function binds the index buffer. It must be overridden
             * in the derived classes.
             */
            virtual void Bind() const = 0;

            /**
             * @brief Unbind the index buffer
             *
             * This function unbinds the index buffer. It must be overridden
             * in the derived classes.
             */
            virtual void Unbind() const = 0;

            /**
             * @brief Get the ID of the index buffer
             *
             * This function returns the ID of the index buffer. It must
             * be overridden in the derived classes.
             *
             * @return The ID of the index buffer
             */
            virtual TE_IndexBufferID GetID() const = 0;
    };

}