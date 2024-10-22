#pragma once

#include <glad/glad.h>
#include "VertexArray.hpp"

namespace TE::APIs::OpenGL
{
    /**
     * @class GL_VertexArray
     *
     * @brief A class to represent an OpenGL vertex array
     *
     * This class is used to represent an OpenGL vertex array. It provides
     * functions to bind and unbind the vertex array, get the ID of the vertex
     * array, add a vertex buffer to the vertex array, and get the vertex and
     * index buffers associated with the vertex array.
     */
    class GL_VertexArray : public TE::Renderer::VertexArray
    {
        public:
            /**
             * @brief Constructor
             *
             * Constructs a new instance of the GL_VertexArray class.
             */
            GL_VertexArray();

            /**
             * @brief Destructor
             *
             * Destroys the current instance of the GL_VertexArray class.
             */
            virtual ~GL_VertexArray();

            /**
             * @brief Bind the vertex array
             *
             * This function binds the OpenGL vertex array associated with this
             * object.
             */
            virtual void Bind() const override;

            /**
             * @brief Unbind the vertex array
             *
             * This function unbinds the OpenGL vertex array associated with this
             * object.
             */
            virtual void Unbind() const override;

            /**
             * @brief Get the ID of the vertex array
             *
             * This function returns the ID of the vertex array associated with
             * this object.
             *
             * @return The ID of the vertex array associated with this object.
             */
            virtual VertexArrayID GetID() const override;

            /**
             * @brief Add a vertex buffer to the vertex array
             *
             * This function adds a vertex buffer to the vertex array associated
             * with this object.
             *
             * @param vtxBuffer The vertex buffer to add.
             */
            virtual void EmplaceVtxBuffer(const std::shared_ptr<TE::Renderer::VertexBuffer>& vtxBuffer) override;

            /**
             * @brief Add an index buffer to the vertex array
             *
             * This function adds an index buffer to the vertex array associated
             * with this object.
             *
             * @param idxBuffer The index buffer to add.
             */
            virtual void EmplaceIdxBuffer(const std::shared_ptr<TE::Renderer::IndexBuffer>& idxBuffer) override;

            /**
             * @brief Get the vertex buffers associated with the vertex array
             *
             * This function returns a constant reference to the vector of vertex
             * buffers associated with this object.
             *
             * @return A constant reference to the vector of vertex buffers
             * associated with this object.
             */
            virtual const std::vector<std::shared_ptr<TE::Renderer::VertexBuffer>>& GetVtxBuffers() const override;

            /**
             * @brief Get the index buffer associated with the vertex array
             *
             * This function returns a constant reference to the index buffer
             * associated with this object.
             *
             * @return A constant reference to the index buffer associated with
             * this object.
             */
            virtual const std::shared_ptr<TE::Renderer::IndexBuffer>& GetIdexBuffer() const override;

        private:
            /**
             * @brief The ID of the vertex array
             *
             * This variable stores the ID of the vertex array associated with
             * this object.
             */
            VertexArrayID m_VertexArrayID = 0;

            /**
             * @brief The vector of vertex buffers associated with the vertex array
             *
             * This variable stores the vector of vertex buffers associated with
             * this object.
             */
            std::vector<std::shared_ptr<TE::Renderer::VertexBuffer>> m_VtxBuffers;

            /**
             * @brief The index buffer associated with the vertex array
             *
             * This variable stores the index buffer associated with this
             * object.
             */
            std::shared_ptr<TE::Renderer::IndexBuffer> m_IdexBuffer;
    };
}