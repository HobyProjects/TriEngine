#include "GLFW.hpp"
#include "InputHandler.hpp"

namespace TE::Events
{
    std::shared_ptr<TE::Events::InputHandler> TE::Events::CreateInputHandler(TE::Core::WindowAPI api)
    {
        switch(api)
        {
            case TE::Core::WindowAPI::GLFW_API:     return std::make_shared<TE::APIs::GLFW::GLFW_InputHandler>();
            default:                                return nullptr;
        };
    }

}