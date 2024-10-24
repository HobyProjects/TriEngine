#include "Window.hpp"

#include "GLFW/GLFW.hpp"

namespace TE::Core
{
    std::shared_ptr<Window> CreateWindow(const String & title, WindowAPI api)
    {
        switch(api)
        {
            case WindowAPI::GLFW_API:               return std::make_shared<TE::APIs::GLFW::GLFW_Window>(title);
            default:                                return nullptr;
        }
    };
}