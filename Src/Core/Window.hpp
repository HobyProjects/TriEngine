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
     * @enum WindowAPI
     *
     * @brief Enumerates the different window APIs that can be used by the engine.
     *
     * The WindowAPI enum is used to identify the different windowing systems
     * available for use by the engine. Each enumerator corresponds to a
     * specific windowing API that can be utilized.
     */
    enum class WindowAPI
    {
        /**
         * @brief The GLFW windowing API is used.
         *
         * This option is selected when the engine is utilizing the GLFW
         * windowing library for creating and managing windows.
         */
        GLFW_API        = 0,

        /**
         * @brief The SDL windowing API is used.
         *
         * This option is selected when the engine is utilizing the SDL
         * (Simple DirectMedia Layer) library for window management.
         */
        SDL_API         = 1,

        /**
         * @brief The native Windows API is used.
         *
         * This option is selected when the engine is using the native
         * Windows API for handling windows in a Windows environment.
         */
        WINDOWS_API     = 2
    };

    /**
     * @class WindowBaseAPI
     *
     * @brief Abstract base class that describes an interface for windowing APIs.
     *
     * This class is used to define the interface for any windowing API that
     * the engine utilizes. It is an abstract base class, meaning that it
     * cannot be instantiated directly, and any derived classes must
     * implement the pure virtual functions declared here.
     *
     * The purpose of this class is to provide a common interface for
     * different windowing APIs, such as GLFW, SDL, and native Windows, so
     * that the engine can easily switch between them.
     */
    class WindowBaseAPI
    {
        public:
            WindowBaseAPI() = default;
            virtual ~WindowBaseAPI() = default;

            /**
             * @brief Initializes the windowing API.
             *
             * This function must be implemented by any derived classes, and
             * is responsible for initializing the windowing API. This may
             * involve loading the necessary libraries, setting up the window
             * management system, and so on.
             */
            virtual bool Init() = 0;

            /**
             * @brief Shuts down the windowing API.
             *
             * This function must be implemented by any derived classes, and
             * is responsible for shutting down the windowing API. This may
             * involve unloading the necessary libraries, tearing down the
             * window management system, and so on.
             */
            virtual void Shutdown() = 0;

            /**
             * @brief Get the windowing API being used.
             * 
             * This pure virtual function is used to retrieve the windowing API that
             * is currently being utilized by the engine. Any class derived from this
             * abstract base class must implement this function to return the specific
             * windowing API being used (e.g., GLFW, SDL, native Windows API).
             * 
             * @return The windowing API being used (e.g., GLFW_API, SDL_API, WINDOWS_API).
             */
            virtual WindowAPI GetAPI() = 0;
    };

    /**
     * @class Window
     * @brief An abstract base class that describes a window.
     *
     * This class is used to define the properties and behavior of a window
     * in the Trimana Engine. It is an abstract base class, meaning that it
     * cannot be instantiated directly, and any derived classes must
     * implement the pure virtual functions declared here.
     */
    class Window
    {
        public:
            /**
             * @brief Default constructor.
             *
             * This default constructor is left empty, as there is no need to
             * initialize any member variables in the base class.
             */
            Window() = default;

            /**
             * @brief Virtual destructor.
             *
             * This virtual destructor is declared here to ensure that any
             * derived classes will have a virtual destructor as well. This
             * is important, as it allows the engine to properly clean up
             * objects when they are destroyed.
             */
            ~Window() = default;

            /**
             * @brief Pure virtual function to retrieve the native window handle.
             *
             * This function is declared as pure virtual, meaning that any
             * derived classes must implement it. It is used to retrieve the
             * native window handle, which is used by the renderer to
             * associate a rendering context with the window.
             *
             * @return a pointer to the native window handle
             */
            virtual WindowAPIPtr GetNativeWindow() = 0;

            /**
             * @brief Pure virtual function to retrieve the window's specification.
             *
             * This function is declared as pure virtual, meaning that any
             * derived classes must implement it. It is used to retrieve the
             * window's specification, which contains information such as the
             * window's width and height, title, and other relevant details.
             *
             * @return a reference to the window's specification
             */
            virtual WindowSpecification& GetWindowSpecification() = 0;

            /**
             * @brief Pure virtual function to retrieve a shared pointer to the window's rendering context.
             *
             * This function is declared as pure virtual, meaning that any
             * derived classes must implement it. It is used to retrieve a
             * shared pointer to the window's rendering context, which is used
             * by the renderer to draw graphics to the window.
             *
             * @return a shared pointer to the window's rendering context
             */
            virtual std::shared_ptr<TE::Renderer::Context> GetContext() = 0;

            /**
             * @brief Pure virtual function to swap the window's buffers.
             *
             * This function is declared as pure virtual, meaning that any
             * derived classes must implement it. It is used to swap the
             * window's buffers, which is necessary to present the graphics
             * drawn to the window to the user.
             */
            virtual void SwapBuffers() = 0;
    };

    /**
     * @brief Creates a new window with the specified title.
     *
     * This function creates a new window with the specified title and
     * returns a shared pointer to it. The window is created using the
     * current windowing API (GLFW, SDL, or native Windows API) and is
     * set up to be used by the renderer to draw graphics.
     *
     * @param title The title of the window to be created.
     * @return a shared pointer to the newly created window
     */
    std::shared_ptr<Window> CreateWindow(const String& title, WindowAPI api = WindowAPI::GLFW_API);
}