#pragma once

#include <memory>
#include "TypeDef.hpp"

namespace TE::Renderer
{
    /**
     * @brief Abstract base class for any rendering context
     *
     * This abstract class defines the interface for any rendering context. The
     * rendering context is responsible for managing the platform-specific
     * rendering context, such as a window, and for making the context current.
     *
     * @note Any implementing class must provide a constructor that takes no
     * arguments, since this class is used as a base class for a factory class.
     */
    class Context
    {
        public:

            /**
             * @brief Constructor
             * 
             * This constructor is left empty. There is no need to initialize
             * anything in the constructor.
             * */
            Context() = default;
            
            /**
             * @brief Destructor
             *
             * This virtual destructor is necessary to ensure that the correct
             * destructor is called when deleting an instance of this class
             * through a pointer to the base class.
             */
            virtual ~Context() = default;

            /**
             * @brief Make this context current
             *
             * Makes the rendering context of this class current. This is
             * necessary before any rendering operations can be performed.
             *
             * @return true if the context was successfully made current, false
             * otherwise
             */
            virtual bool MakeContextCurrent() = 0;

            /**
             * @brief Swap the front and back buffers
             *
             * This function swaps the front and back buffers of the rendering
             * context, which is necessary to present the rendered image to the
             * user.
             */
            virtual void SwapBuffers() = 0;

            /**
             * @brief Set the swap interval
             *
             * This function sets the swap interval of the rendering context. The
             * swap interval determines how often the front and back buffers are
             * swapped. A swap interval of 0 means that the buffers are swapped
             * as soon as possible, while a swap interval of 1 means that the
             * buffers are swapped once per frame.
             *
             * @param interval the swap interval to use
             */
            virtual void ChangeSwapInterval(UInt32 interval) = 0;
    };

    /**
     * @brief Creates a platform-specific rendering context
     *
     * This function creates a platform-specific rendering context. The
     * rendering context is created based on the type of window that is
     * passed in. The platform-specific rendering context is then wrapped
     * in a Context object and returned to the caller.
     *
     * @param window the native window handle to use for creating the
     * rendering context
     *
     * @return a shared pointer to the created Context object
     */
    std::shared_ptr<Context> CreateContext(void* window);
}