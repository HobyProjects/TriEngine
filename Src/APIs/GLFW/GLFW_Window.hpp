#pragma once

#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Window.hpp"
#include "Context.hpp"

namespace TE::APIs::GLFW
{
    /**
     * @class GLFW_API
     *
     * @brief A class that represents the GLFW windowing API
     *
     * This class is used to represent the GLFW windowing API. It provides
     * functions to initialize and shut down the GLFW windowing API.
     *
     * @note This class is an implementation of the WindowBaseAPI abstract
     * base class, which is used to define the interface for any windowing API
     * that the engine utilizes.
     */
    class GLFW_API : public TE::Core::WindowBaseAPI
    {
        public:
            /**
             * @brief Constructor
             *
             * This constructor is used to initialize the GLFW_API class.
             */
            GLFW_API() = default;

            /**
             * @brief Destructor
             *
             * This destructor is used to shut down the GLFW_API class.
             */
            virtual ~GLFW_API() = default;

            /**
             * @brief Initializes the GLFW windowing API.
             *
             * This function is used to initialize the GLFW windowing API. It
             * is responsible for loading the GLFW library and initializing the
             * GLFW context.
             *
             * @return true if the GLFW windowing API was successfully
             * initialized, false otherwise.
             */
            virtual bool Init() override;

            /**
             * @brief Shuts down the GLFW windowing API.
             *
             * This function is used to shut down the GLFW windowing API. It
             * is responsible for unloading the GLFW library and shutting down
             * the GLFW context.
             */
            virtual void Shutdown() override;

            /**
             * @brief Returns the WindowAPI type of the windowing API associated
             * with this GLFW_API class.
             *
             * This function is used to return the WindowAPI type of the windowing
             * API associated with this GLFW_API class. Since this class is a
             * GLFW_API class, it is returning a WindowAPI type of GLFW_API.
             *
             * @return The WindowAPI type associated with this GLFW_API class.
             */
            virtual TE::Core::WindowAPI GetAPI() override
            {
                return TE::Core::WindowAPI::GLFW_API;
            }
    };

    /**
     * @class GLFW_Window
     *
     * @brief A class that represents a window in the GLFW windowing API
     *
     * This class is used to represent a window in the GLFW windowing API. It
     * provides functions to create a window, get the native window pointer, get
     * the window specification, get the context associated with the window, and
     * swap the window's buffers.
     *
     * @note This class is an implementation of the Window abstract base class,
     * which is used to define the interface for any window that the engine
     * utilizes.
     */
    class GLFW_Window : public TE::Core::Window
    {
        public:
            /**
             * @brief Constructor
             *
             * This constructor is used to initialize the GLFW_Window class.
             * It takes a string argument, which is the title of the window that
             * will be created.
             *
             * @param title The title of the window that will be created.
             */
            GLFW_Window(const String& title);

            /**
             * @brief Destructor
             *
             * This destructor is used to shut down the GLFW_Window class. It
             * is responsible for destroying the window and releasing any
             * associated resources.
             */
            ~GLFW_Window();

            /**
             * @brief Gets the native window pointer
             *
             * This function is used to get the native window pointer, which can
             * be used to access the window's underlying platform-specific data.
             *
             * @return A pointer to the native window.
             */
            virtual void* GetNativeWindow() override { return (void*)m_NativeWindow; }

            /**
             * @brief Gets the window specification
             *
             * This function is used to get the window specification, which
             * contains information about the window such as its dimensions, color
             * depth, and refresh rate.
             *
             * @return A reference to the window specification.
             */
            virtual TE::Core::WindowSpecification& GetWindowSpecification() override { return m_Specification; }

            /**
             * @brief Gets the context associated with the window
             *
             * This function is used to get the context associated with the
             * window, which is used to render graphics to the window.
             *
             * @return A shared pointer to the context associated with the window.
             */
            virtual std::shared_ptr<TE::Renderer::Context> GetContext() override { return m_Context; }

            /**
             * @brief Swaps the window's buffers
             *
             * This function is used to swap the window's buffers, which is
             * necessary to display the rendered graphics.
             */
            virtual void SwapBuffers() override;

        private:
            /**
             * @brief The native window pointer
             *
             * This is a pointer to the native window, which can be used to
             * access the window's underlying platform-specific data.
             */
            GLFWwindow* m_NativeWindow{nullptr};

            /**
             * @brief The window specification
             *
             * This contains information about the window such as its dimensions,
             * color depth, and refresh rate.
             */
            TE::Core::WindowSpecification m_Specification{};

            /**
             * @brief The context associated with the window
             *
             * This is the context associated with the window, which is used to
             * render graphics to the window.
             */
            std::shared_ptr<TE::Renderer::Context> m_Context{nullptr};
    };
}