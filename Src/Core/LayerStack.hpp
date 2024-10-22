#pragma once

#include "Layer.hpp"

namespace TE::Core
{
    /**
     * @class LayerStack
     *
     * @brief A stack of layers that can be iterated over and layers can be added or removed
     *
     * A layer stack is a stack of layers that can be iterated over in the reverse order that they were added. Layers can be
     * added to the stack as layers or as overlays. Layers are added at the end of the stack and overlays are added at the
     * beginning of the stack. Layers can be removed from the stack by passing a pointer to the layer to be removed.
     */
    class LayerStack
    {
        public:
            /**
             * @brief Constructor
             *
             * The constructor initializes the stack with no layers.
             */
            LayerStack() = default;

            /**
             * @brief Destructor
             *
             * The destructor is declared as virtual to ensure that the
             * correct destructor is called when deleting a layer stack
             * through a pointer to the base class.
             */
            ~LayerStack();

            /**
             * @brief PushLayer adds a layer to the end of the stack
             *
             * @param layer The layer to be added to the stack
             *
             * This function adds the layer to the end of the stack. It
             * is called when a layer is added to the layer stack.
             */
            void PushLayer(std::shared_ptr<Layer> layer);

            /**
             * @brief PushOverlay adds a layer to the beginning of the stack
             *
             * @param overlay The layer to be added to the stack
             *
             * This function adds the layer to the beginning of the stack. It
             * is called when a layer is added to the layer stack as an overlay.
             */
            void PushOverlay(std::shared_ptr<Layer> overlay);

            /**
             * @brief PopLayer removes a layer from the stack
             *
             * @param layer The layer to be removed from the stack
             *
             * This function removes the layer from the stack. It
             * is called when a layer is removed from the layer stack.
             */
            void PopLayer(std::shared_ptr<Layer> layer);

            /**
             * @brief PopOverlay removes a layer from the stack
             *
             * @param overlay The layer to be removed from the stack
             *
             * This function removes the layer from the stack. It
             * is called when a layer is removed from the layer stack as an overlay.
             */
            void PopOverlay(std::shared_ptr<Layer> overlay);

            /**
             * @brief begin returns an iterator pointing to the beginning of the stack
             *
             * @return An iterator pointing to the beginning of the stack
             */
            std::vector<std::shared_ptr<Layer>>::iterator begin() { return m_Layers.begin(); }

            /**
             * @brief end returns an iterator pointing to the end of the stack
             *
             * @return An iterator pointing to the end of the stack
             */
            std::vector<std::shared_ptr<Layer>>::iterator end() { return m_Layers.end(); }

            /**
             * @brief begin returns an iterator pointing to the beginning of the stack (const)
             *
             * @return An iterator pointing to the beginning of the stack
             */
            std::vector<std::shared_ptr<Layer>>::const_iterator begin() const { return m_Layers.begin(); }

            /**
             * @brief end returns an iterator pointing to the end of the stack (const)
             *
             * @return An iterator pointing to the end of the stack
             */
            std::vector<std::shared_ptr<Layer>>::const_iterator end() const { return m_Layers.end(); }

            /**
             * @brief rbegin returns an iterator pointing to the beginning of the stack in reverse order
             *
             * @return An iterator pointing to the beginning of the stack in reverse order
             */
            std::vector<std::shared_ptr<Layer>>::reverse_iterator rbegin() { return m_Layers.rbegin(); }

            /**
             * @brief rend returns an iterator pointing to the end of the stack in reverse order
             *
             * @return An iterator pointing to the end of the stack in reverse order
             */
            std::vector<std::shared_ptr<Layer>>::reverse_iterator rend() { return m_Layers.rend(); }

            /**
             * @brief rbegin returns an iterator pointing to the beginning of the stack in reverse order (const)
             *
             * @return An iterator pointing to the beginning of the stack in reverse order
             */
            std::vector<std::shared_ptr<Layer>>::const_reverse_iterator rbegin() const { return m_Layers.rbegin(); }

            /**
             * @brief rend returns an iterator pointing to the end of the stack in reverse order (const)
             *
             * @return An iterator pointing to the end of the stack in reverse order
             */
            std::vector<std::shared_ptr<Layer>>::const_reverse_iterator rend() const { return m_Layers.rend(); }

        private:
            /**
             * @brief m_Layers is a vector of layers that make up the stack
             *
             * This vector is used to store the layers that make up the stack. It
             * is used by the functions that iterate over the stack and by the
             * functions that add or remove layers from the stack.
             */
            std::vector<std::shared_ptr<Layer>> m_Layers;

            /**
             * @brief m_LayerInsertIndex is the index where the next layer should be inserted
             *
             * This variable is used to keep track of the index where the next layer should be
             * inserted. It is used by the functions that add layers to the stack.
             */
            UInt32 m_LayerInsertIndex = 0;
    };
}