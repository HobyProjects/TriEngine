#pragma once

#include "Base.hpp"
#include "TypeDef.hpp"

namespace TE::Renderer
{
    /**
     * @enum RendererAPI
     *
     * @brief Enumerates the different rendering APIs that can be used by the
     * engine.
     *
     * The RendererAPI enum is used to identify the different rendering APIs
     * that can be used by the engine. The engine can be compiled to use any of
     * the following rendering APIs: OpenGL, Vulkan, and DirectX.
     */
    enum class RendererAPI
    {
        /**
         * @brief No rendering API is used.
         *
         * This option is used when the engine is not using any rendering API.
         */
        None        = TE_BIT(0),

        /**
         * @brief The OpenGL rendering API is used.
         *
         * This option is used when the engine is compiled to use the OpenGL
         * rendering API.
         */
        OpenGL      = TE_BIT(1),

        /**
         * @brief The Vulkan rendering API is used.
         *
         * This option is used when the engine is compiled to use the Vulkan
         * rendering API.
         */
        Vulkan      = TE_BIT(2),

        /**
         * @brief The DirectX rendering API is used.
         *
         * This option is used when the engine is compiled to use the DirectX
         * rendering API.
         */
        DirectX     = TE_BIT(3)
    };

    /**
     * @class Renderer
     *
     * @brief A class to represent the renderer.
     *
     * The Renderer class is used to represent the renderer. It provides
     * functions to initialize and shutdown the renderer, get the currently
     * used rendering API, clear the screen, and set the viewport.
     *
     * @note This class is a singleton class, meaning that only one instance of
     * it can exist at a time. This is enforced by making the constructor and
     * destructor private.
     */
    class Renderer
    {
        private:
            /**
             * @brief Constructor
             *
             * This constructor is left private to prevent external code from
             * directly constructing the class. This is done to enforce the
             * singleton pattern.
             */
            Renderer() = default;

            /**
             * @brief Destructor
             *
             * This destructor is left private to prevent external code from
             * directly destroying the class. This is done to enforce the
             * singleton pattern.
             */
            ~Renderer() = default;

        public:
            /**
             * @brief Initializes the renderer.
             *
             * This function initializes the renderer. It is called by the
             * engine when it starts up.
             */
            static void Init();

            /**
             * @brief Shuts down the renderer.
             *
             * This function shuts down the renderer. It is called by the
             * engine when it shuts down.
             */
            static void Shutdown();

            /**
             * @brief Gets the currently used rendering API.
             *
             * This function gets the currently used rendering API. It returns
             * an enum value representing the currently used rendering API.
             *
             * @return The currently used rendering API.
             */
            static RendererAPI GetAPI();

            /**
             * @brief Changes the currently used rendering API.
             *
             * This function changes the currently used rendering API. It is
             * called by the engine when the user wants to switch to a
             * different rendering API.
             *
             * @param api The new rendering API to use.
             */
            static void ChangeAPI(RendererAPI api);

            /**
             * @brief Clears the screen.
             *
             * This function clears the screen. It is called by the engine at
             * the beginning of each frame.
             */
            static void Clear();

            /**
             * @brief Clears the screen with a color.
             *
             * This function clears the screen with the specified color. It is
             * called by the engine at the beginning of each frame.
             *
             * @param color The color to clear the screen with.
             */
            static void ClearColor(const glm::vec4& color);

            /**
             * @brief Sets the viewport.
             *
             * This function sets the viewport. It is called by the engine when
             * the window is resized.
             *
             * @param x The x-coordinate of the upper-left corner of the
             * viewport.
             * @param y The y-coordinate of the upper-left corner of the
             * viewport.
             * @param width The width of the viewport.
             * @param height The height of the viewport.
             */
            static void SetViewport(UInt32 x, UInt32 y, UInt32 width, UInt32 height);
    };
}