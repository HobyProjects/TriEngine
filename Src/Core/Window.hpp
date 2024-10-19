#pragma once

#include <string>
#include <memory>

#include "OpenGL.hpp"

#include "Renderer.hpp"
#include "Context.hpp"
#include "TypeDef.hpp"

namespace TE::Core
{
    /**
     * @brief Enum representing the state of the window.
     * 
     * This enum is used to represent the state of the window, such as minimized, maximized, or normal.
     */
    enum class WindowState
    {
        Minimized = 0,  /// The window is minimized.
        Maximized,      /// The window is maximized.
        Normal          /// The window is in normal state.
    };


    /**
     * @struct WindowSpecification
     * 
     * @brief A structure that holds various properties for window configuration.
     * 
     * This structure is used to define the specifications and properties of a window,
     * including its dimensions, color bit depths, refresh rate, and state-related flags.
     */
    struct WindowSpecification
    {
        String Title{std::string()};          ///< Title of the window.
        UInt32 Width{0};                      ///< Width of the window in pixels.
        UInt32 Height{0};                     ///< Height of the window in pixels.
        bool IsVSyncEnabled{false};           ///< Flag indicating if VSync is enabled.
        bool IsActive{false};                 ///< Flag indicating if the window is active.
        bool IsFocused{false};                ///< Flag indicating if the window is focused.

        WindowState WindowState{WindowState::Normal}; ///< Current state of the window (minimized, maximized, normal).

        UInt32 RedColorBits{8};               ///< Number of bits for red color in the color buffer.
        UInt32 GreenColorBits{8};             ///< Number of bits for green color in the color buffer.
        UInt32 BlueColorBits{8};              ///< Number of bits for blue color in the color buffer.
        UInt32 AlphaColorBits{8};             ///< Number of bits for alpha channel in the color buffer.
        UInt32 DepthColorBits{24};            ///< Number of bits for the depth buffer.
        UInt32 StencilColorBits{8};           ///< Number of bits for the stencil buffer.

        UInt32 RefreshRate{60};               ///< Refresh rate of the window in Hz.
        UInt32 FixedWidth{0};                 ///< Fixed width of the window (if applicable).
        UInt32 FixedHeight{0};                ///< Fixed height of the window (if applicable).
        UInt32 MinWidth{1280};                ///< Minimum allowable width of the window.
        UInt32 MinHeight{720};                ///< Minimum allowable height of the window.

        UInt32 PosX{0};                       ///< X position of the window on the screen.
        UInt32 PosY{0};                       ///< Y position of the window on the screen.

        Int32 FramebufferWidth{0};           ///< Width of the window's framebuffer.
        Int32 FramebufferHeight{0};          ///< Height of the window's framebuffer.
    };

    /**
     * @class Window
     *
     * @brief A class to represent a window in the application.
     *
     * The Window class is responsible for creating and managing a window
     * using GLFW and providing access to the native window handle, 
     * window specifications, and rendering context.
     */
    class Window
    {
        public:
            /**
             * @brief Constructs a Window with the given title.
             *
             * @param title The title of the window.
             */
            Window(const String& title="Trimana Engine");

            /**
             * @brief Destructor for the Window class.
             */
            ~Window();

            /**
             * @brief Gets the native GLFW window handle.
             *
             * @return A pointer to the GLFWwindow.
             */
            GLFWwindow* GetNativeWindow() const { return m_NativeWindow; }

            /**
             * @brief Gets the window specification.
             *
             * @return A reference to the WindowSpecification object.
             */
            WindowSpecification& GetWindowSpecification() { return m_Specification; }

            /**
             * @brief Gets the OpenGL rendering context.
             *
             * @return A shared pointer to the rendering Context.
             */
            std::shared_ptr<TE::Renderer::Context> GetOpenGLContext() const { return m_Context; }

            /**
             * @brief Swaps the front and back buffers.
             */
            void SwapBuffers();

        private:
            GLFWwindow* m_NativeWindow{nullptr}; ///< The native GLFW window handle.
            WindowSpecification m_Specification; ///< Specifications of the window.
            std::shared_ptr<TE::Renderer::Context> m_Context{nullptr}; ///< The OpenGL rendering context.
    };
}