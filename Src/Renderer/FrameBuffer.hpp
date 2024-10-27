#pragma once

#include "TypeDef.hpp"

namespace TE::Renderer
{
    /**
     * @struct FrameBufferSpecifications
     *
     * @brief This struct contains specifications about a frame buffer
     *
     * This struct is used to specify the width and height of a frame buffer
     * and whether it is a swap chain target (i.e., whether it is a window
     * that the user can see).
     */
    struct FrameBufferSpecifications 
    {
        /**
         * @var Width The width of the frame buffer in pixels
         */
        UInt32 Width{0};

        /**
         * @var Height The height of the frame buffer in pixels
         */
        UInt32 Height{0};

        /**
         * @var SwapChainTarget Whether the frame buffer is a swap chain
         * target. If this is true, the frame buffer is a window that the
         * user can see. If this is false, the frame buffer is an off-screen
         * buffer that is not visible to the user.
         */
        Boolean SwapChainTarget{TE_FALSE};
    };

    /**
     * @class FrameBuffer
     *
     * @brief This class represents a frame buffer
     *
     * A frame buffer is a buffer that is used to store the rendered image.
     * It is a window that the user can see and is typically a swap chain
     * target.
     */
    class FrameBuffer
    {
        public:
            /**
             * @brief Constructs a new frame buffer
             *
             * This constructor does not take any arguments and constructs a
             * new frame buffer with default values.
             */
            FrameBuffer() = default;

            /**
             * @brief Destroys the frame buffer
             *
             * This destructor does not take any arguments and is used to
             * destroy the frame buffer.
             */
            virtual ~FrameBuffer() = default;

            /**
             * @brief Binds the frame buffer
             *
             * This function takes no arguments and is used to bind the frame
             * buffer. Binding the frame buffer makes it the current target
             * for rendering.
             */
            virtual void Bind() const = 0;

            /**
             * @brief Unbinds the frame buffer
             *
             * This function takes no arguments and is used to unbind the
             * frame buffer. Unbinding the frame buffer makes it no longer
             * the current target for rendering.
             */
            virtual void Unbind() const = 0;

            /**
             * @brief Resizes the frame buffer
             *
             * This function takes two arguments, the width and height of the
             * frame buffer in pixels, and is used to resize the frame
             * buffer.
             *
             * @param width The new width of the frame buffer in pixels
             * @param height The new height of the frame buffer in pixels
             */
            virtual void ResizeFrame(UInt32 width, UInt32 height) = 0;

            /**
             * @brief Gets the ID of the frame buffer
             *
             * This function takes no arguments and is used to get the ID of
             * the frame buffer. The ID is a unique identifier for the frame
             * buffer.
             *
             * @returns The ID of the frame buffer
             */
            virtual FrameBufferID GetFrameBufferID() const = 0;

            /**
             * @brief Gets the ID of the color attachment of the frame buffer
             *
             * This function takes no arguments and is used to get the ID of
             * the color attachment of the frame buffer. The ID is a unique
             * identifier for the color attachment.
             *
             * @returns The ID of the color attachment of the frame buffer
             */
            virtual FrameBufferAttachmentID GetColorAttachment() const = 0;

            /**
             * @brief Gets the specifications of the frame buffer
             *
             * This function takes no arguments and is used to get the
             * specifications of the frame buffer. The specifications
             * include the width and height of the frame buffer in pixels and
             * whether it is a swap chain target.
             *
             * @returns The specifications of the frame buffer
             */
            virtual FrameBufferSpecifications& GetFrameSpecification() = 0;

        protected:
            /**
             * @brief Creates a new frame buffer
             *
             * This function takes no arguments and is used to create a new
             * frame buffer. The specifications of the frame buffer are
             * specified in the derived class.
             */
            virtual void CreateFrame() = 0;
    };
}