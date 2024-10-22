#pragma once

#include <memory>
#include "Buffers.hpp"
#include "TypeDef.hpp"

namespace TE::Renderer
{
    /**
     * @class VertexArray
     *
     * @brief A class that represents a vertex array
     *
     * This class provides an interface for a vertex array, which is used in 
     * rendering to manage vertex and index buffers. It includes functions 
     * to bind and unbind the vertex array, as well as to get its ID.
     */
    class VertexArray
    {
        public:
            /**
             * @brief Default constructor
             *
             * Initializes a new instance of the VertexArray class.
             */
            VertexArray() = default;

            /**
             * @brief Destructor
             *
             * Destroys the instance of the VertexArray class.
             */
            virtual ~VertexArray() = default;

            /**
             * @brief Bind the vertex array
             *
             * This function binds the vertex array for rendering.
             */
            virtual void Bind() const = 0;

            /**
             * @brief Unbind the vertex array
             *
             * This function unbinds the vertex array from rendering.
             */
            virtual void Unbind() const = 0;

            /**
             * @brief Get the ID of the vertex array
             *
             * This function returns the ID of the vertex array.
             *
             * @return The ID of the vertex array.
             */
            virtual VertexArrayID GetID() const = 0;

            /**
             * @brief Add a vertex buffer to the vertex array
             *
             * @param vtxBuffer The vertex buffer to add.
             */
            virtual void EmplaceVtxBuffer(const std::shared_ptr<VertexBuffer>& vtxBuffer) = 0;

            /**
             * @brief Add an index buffer to the vertex array
             *
             * @param idxBuffer The index buffer to add.
             */
            virtual void EmplaceIdxBuffer(const std::shared_ptr<IndexBuffer>& idxBuffer) = 0;

            /**
             * @brief Get the vertex buffers associated with the vertex array
             *
             * @return A vector of shared pointers to the vertex buffers.
             */
            virtual const std::vector<std::shared_ptr<VertexBuffer>>& GetVtxBuffers() const = 0;

            /**
             * @brief Get the index buffer associated with the vertex array
             *
             * @return A shared pointer to the index buffer.
             */
            virtual const std::shared_ptr<IndexBuffer>& GetIdexBuffer() const = 0;
    };

    /**
     * @brief Create a new vertex array
     * 
     * This function creates a new vertex array based on the current rendering API.
     * It returns a shared pointer to the new vertex array.
     * 
     * @return A shared pointer to the new vertex array
     */
    std::shared_ptr<VertexArray> CreateVertexArray();
}