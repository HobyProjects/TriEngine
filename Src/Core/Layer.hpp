#pragma once

#include "TypeDef.hpp"
#include "Timer.hpp"
#include "Events.hpp"

namespace TE::Core
{
    /**
     * @class Layer
     *
     * @brief A base class for all layers in the engine
     *
     * Layers are objects that can be attached to the engine and are
     * responsible for rendering, updating, and handling events. They are
     * used to organize the code into logical groups and to provide a
     * way to manage the lifetime of objects in the engine.
     */
    class Layer
    {
        public:
            /**
             * @brief Constructor
             *
             * @param name The name of the layer
             */
            Layer(const String& name) : m_Name(name) {}

            /**
             * @brief Destructor
             *
             * The destructor is declared as virtual to ensure that the
             * correct destructor is called when deleting a layer through
             * a pointer to the base class.
             */
            virtual ~Layer() = default;

            /**
             * @brief OnAttach is called when the layer is attached to the engine
             *
             * This function is called when the layer is attached to the
             * engine. It is used to initialize the layer and to setup any
             * necessary resources.
             */
            virtual void OnAttach() {}

            /**
             * @brief OnDetach is called when the layer is detached from the engine
             *
             * This function is called when the layer is detached from the
             * engine. It is used to clean up any resources that were
             * allocated by the layer.
             */
            virtual void OnDetach() {}

            /**
             * @brief OnUpdate is called when the layer is updated
             *
             * This function is called when the layer is updated. It is
             * used to update the layer and to handle any game logic that
             * needs to be processed.
             */
            virtual void OnUpdate(Timer deltaTime) {}

            /**
             * @brief OnEvent is called when an event is received
             *
             * This function is called when an event is received. It is
             * used to handle events such as key presses, mouse clicks,
             * and window resizing.
             */
            virtual void OnEvent(TE::Events::Event& event) {}

            /**
             * @brief OnGuiRendering is called when the layer is rendered
             *
             * This function is called when the layer is rendered. It is
             * used to render any GUI elements that the layer needs to
             * display.
             */
            virtual void OnGuiRendering() {}

            /**
             * @brief GetName gets the name of the layer
             *
             * @return The name of the layer
             */
            const String& GetName() const { return m_Name; }

        protected:
            String m_Name;
    };
}