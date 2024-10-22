#include "LayerStack.hpp"

namespace TE::Core
{
    LayerStack::~LayerStack()
    {
        for(auto& layer : m_Layers)
        {
            layer->OnDetach();
        }
    }

    void LayerStack::PushLayer(std::shared_ptr<Layer> layer)
    {
        m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layer);
    }

    void LayerStack::PushOverlay(std::shared_ptr<Layer> overlay)
    {
        m_Layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(std::shared_ptr<Layer> layer)
    {
        auto it = std::find(m_Layers.begin(), m_Layers.begin() + m_LayerInsertIndex, layer);
        if(it != m_Layers.end())
        {
            layer->OnDetach();
            m_Layers.erase(it);
            m_LayerInsertIndex--;
        }
    }

    void LayerStack::PopOverlay(std::shared_ptr<Layer> overlay)
    {
        auto it = std::find(m_Layers.begin() + m_LayerInsertIndex, m_Layers.end(), overlay);
        if(it != m_Layers.end())
        {
            overlay->OnDetach();
            m_Layers.erase(it);
        }
    }


}