#pragma once

#include <imgui/imgui.h>
#include <imgui/imgui_impl_opengl3.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_internal.h>

#include "Layer.hpp"
#include "Window.hpp"

namespace TE::UI
{
    /**
     * @enum UITheme
     *
     * @brief Enumerates the different themes that can be used for the ImGui UI
     *
     * The UITheme enum is used to specify which theme to use for the ImGui UI.
     * Currently, the following themes are supported:
     *
     * - Drak:   A dark theme with a black background and light text.
     * - Light:  A light theme with a white background and dark text.
     * - Classic: The classic ImGui theme with a light background and dark text.
     */
    enum class UITheme
    {
        Drak    = 0,    ///< A dark theme with a black background and light text.
        Light   = 1,    ///< A light theme with a white background and dark text.
        Classic = 2     ///< The classic ImGui theme with a light background and dark text.
    };

    /**
     * @class UILayer
     *
     * @brief A layer that renders an ImGui user interface
     *
     * The UILayer class is a layer that renders an ImGui user interface. It is
     * responsible for rendering the ImGui UI and for handling events that are
     * sent to the UI.
     */
    class UILayer final : TE::Core::Layer
    {
        public:
            /**
             * @brief Default constructor.
             *
             * This default constructor is used to construct an instance of the
             * UILayer class with the default name "UILayer".
             */
            UILayer() : TE::Core::Layer("UILayer")
            {}

            /**
             * @brief Constructor.
             *
             * This constructor is used to construct an instance of the UILayer
             * class with a given window and theme.
             *
             * @param window The window that the layer is attached to.
             * @param theme  The theme of the UI. Defaults to UITheme::Drak.
             */
            UILayer(std::shared_ptr<TE::Core::Window> window, UITheme theme = UITheme::Drak);

            /**
             * @brief Destructor
             *
             * This is the destructor of the UILayer class. It is declared as
             * virtual to allow for proper destruction of the object when it is
             * destroyed polymorphically.
             */
            virtual ~UILayer() = default;

            /**
             * @brief Called when the layer is attached to a window.
             *
             * This function is called when the layer is attached to a window. It
             * is used to initialize the ImGui context and to set up the UI.
             */
            virtual void OnAttach() override;

            /**
             * @brief Called when the layer is detached from a window.
             *
             * This function is called when the layer is detached from a window.
             * It is used to clean up the ImGui context and to release any
             * resources that are associated with the UI.
             */
            virtual void OnDetach() override;

            /**
             * @brief Called when an event is received.
             *
             * This function is called when an event is received. It is used to
             * handle events that are sent to the UI.
             *
             * @param event The event that was received.
             */
            virtual void OnEvent(TE::Events::Event& event) override;

            /**
             * @brief Called at the beginning of the frame to start the ImGui frame.
             *
             * This function is called at the beginning of the frame to start the
             * ImGui frame. It is used to initialize the ImGui context and to
             * prepare the UI for rendering.
             */
            void Begin();

            /**
             * @brief Called at the end of the frame to end the ImGui frame.
             *
             * This function is called at the end of the frame to end the ImGui
             * frame. It is used to clean up the ImGui context and to release any
             * resources that are associated with the UI.
             */
            void End();

            /**
             * @brief Sets whether events are processed by the ImGui UI.
             *
             * This function is used to set whether events are processed by the
             * ImGui UI. If set to true, the ImGui UI will process events that
             * are received. If set to false, the ImGui UI will not process events
             * that are received.
             *
             * @param allowEvents Whether events are processed by the ImGui UI.
             */
            void AllowEvents(bool allowEvents);

            /**
             * @brief Sets the theme of the ImGui UI.
             *
             * This function is used to set the theme of the ImGui UI. The theme
             * determines the style and colors of the UI.
             *
             * @param theme The theme of the ImGui UI.
             */
            void SetTheme(UITheme theme);

        private:
            /**
             * @brief Sets the theme of the ImGui UI to dark.
             *
             * This function is used to set the theme of the ImGui UI to dark.
             * The dark theme is a dark theme that is easy on the eyes and is
             * suitable for most users.
             */
            void SetDarkTheme();

            /**
             * @brief Sets the theme of the ImGui UI to light.
             *
             * This function is used to set the theme of the ImGui UI to light.
             * The light theme is a light theme that is easy on the eyes and is
             * suitable for most users.
             */
            void SetLightTheme();

            /**
             * @brief Sets the theme of the ImGui UI to classic.
             *
             * This function is used to set the theme of the ImGui UI to classic.
             * The classic theme is the default theme of ImGui and is suitable for
             * most users.
             */
            void SetClassicTheme();

        private:
            /**
             * @brief Pointer to the window associated with the UI layer.
             */
            std::shared_ptr<TE::Core::Window> m_Window{nullptr};

            /**
             * @brief Flag indicating whether events are allowed to be processed by the UI.
             */
            bool m_AllowEvents{true};

            /**
             * @brief The theme of the ImGui UI.
             */
            UITheme m_Theme{UITheme::Drak};
    };
}