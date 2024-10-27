#include "GLFW_EventsReceiver.hpp"

namespace TE::APIs::GLFW
{
    static Ref<TE::Core::IWindow> s_Window = nullptr;
    static TE::Events::EventCallback s_EventCallback;

    static void SetCallBacks()
    {
        glfwSetWindowCloseCallback((GLFWwindow*)s_Window->GetNativeWindow(), [](GLFWwindow* window) 
        {
            TE::Events::AppWindowCloseEvent windowClose;
            s_EventCallback(windowClose); 
        });

        glfwSetWindowSizeCallback((GLFWwindow*)s_Window->GetNativeWindow(), [](GLFWwindow* window, int width, int height) 
        {
            TE::Events::AppWindowResizeEvent windowResize(width, height);
            s_Window->GetWindowSpecification().Width = width;
            s_Window->GetWindowSpecification().Height = height;
            s_EventCallback(windowResize);
        });

        glfwSetWindowPosCallback((GLFWwindow*)s_Window->GetNativeWindow(), [](GLFWwindow* window, int x, int y) 
        {
            TE::Events::AppWindowPosChangeEvent windowPosChange(x, y);
            s_Window->GetWindowSpecification().PosX = x;
            s_Window->GetWindowSpecification().PosY = y;
            s_EventCallback(windowPosChange);
        });

        glfwSetWindowFocusCallback((GLFWwindow*)s_Window->GetNativeWindow(), [](GLFWwindow* window, int focused) 
        {
            if (focused) {
                TE::Events::AppWindowFocusGainEvent windowFocusGain;
                s_Window->GetWindowSpecification().IsFocused = true;
                s_EventCallback(windowFocusGain);
            } 
            else {
                TE::Events::AppWindowFocusLostEvent windowFocusLost;
                s_Window->GetWindowSpecification().IsFocused = false;
                s_EventCallback(windowFocusLost);
            }
        });

        glfwSetWindowMaximizeCallback((GLFWwindow*)s_Window->GetNativeWindow(), [](GLFWwindow* window, int maximized) 
        {
            TE::Events::AppWindowMaximizeEvent windowMaximized;
            s_Window->GetWindowSpecification().WindowState = TE::Core::WindowState::Maximized;
            s_EventCallback(windowMaximized);
        });

        glfwSetWindowIconifyCallback((GLFWwindow*)s_Window->GetNativeWindow(), [](GLFWwindow* window, int iconified) 
        {
            TE::Events::AppWindowMinimizeEvent windowMinimized;
            s_Window->GetWindowSpecification().WindowState = TE::Core::WindowState::Minimized;
            s_EventCallback(windowMinimized);
        });

        glfwSetFramebufferSizeCallback((GLFWwindow*)s_Window->GetNativeWindow(), [](GLFWwindow* window, int width, int height) 
        {
            TE::Events::AppWindowFrameResizeEvent windowFrameResize(width, height);
            s_Window->GetWindowSpecification().FramebufferWidth = width;
            s_Window->GetWindowSpecification().FramebufferHeight = height;
            s_EventCallback(windowFrameResize);
        });

        glfwSetCursorEnterCallback((GLFWwindow*)s_Window->GetNativeWindow(), [](GLFWwindow* window, int entered) 
        {
            if (entered) {
                TE::Events::MouseCursorEnterEvent cursorEnter;
                s_EventCallback(cursorEnter);
            } 
            else {
                TE::Events::MouseCursorLeaveEvent cursorLeave;
                s_EventCallback(cursorLeave);
            }
        });

        glfwSetCursorPosCallback((GLFWwindow*)s_Window->GetNativeWindow(), [](GLFWwindow* window, double x, double y) 
        {
            TE::Events::MouseCursorPosChangeEvent cursorMove(x, y);
            s_EventCallback(cursorMove);
        });

        glfwSetScrollCallback((GLFWwindow*)s_Window->GetNativeWindow(), [](GLFWwindow* window, double xoffset, double yoffset) 
        {
            TE::Events::MouseScrollEvent scroll(xoffset, yoffset);
            s_EventCallback(scroll);
        });

        glfwSetMouseButtonCallback((GLFWwindow*)s_Window->GetNativeWindow(), [](GLFWwindow* window, int button, int action, int mods) 
        {
            if(action == GLFW_PRESS) {
                TE::Events::MouseButtonPressEvent mouseButtonPress(static_cast<TE::Core::MouseButton>(button));
                s_EventCallback(mouseButtonPress);
            } 

            if(action == GLFW_RELEASE) {
                TE::Events::MouseButtonReleaseEvent mouseButtonRelease(static_cast<TE::Core::MouseButton>(button));
                s_EventCallback(mouseButtonRelease);
            }
        });

        glfwSetKeyCallback((GLFWwindow*)s_Window->GetNativeWindow(), [](GLFWwindow* window, int key, int scancode, int action, int mods) 
        {
            if(action == GLFW_PRESS) {
                TE::Events::KeyboardKeyPressEvent keyPress((TE::Core::KeyCodes)key);
                s_EventCallback(keyPress);
            } 

            if(action == GLFW_RELEASE) {
                TE::Events::KeyboardKeyReleaseEvent keyRelease((TE::Core::KeyCodes)key);
                s_EventCallback(keyRelease);
            }
            
            if(action == GLFW_REPEAT) {
                TE::Events::KeyboardKeyRepeatEvent keyRepeat((TE::Core::KeyCodes)key);
                s_EventCallback(keyRepeat);
            }
        });

        glfwSetCharCallback((GLFWwindow*)s_Window->GetNativeWindow(), [](GLFWwindow* window, unsigned int codepoint) 
        {
            TE::Events::KeyboardKeyCharEvent keyChar(codepoint);
            s_EventCallback(keyChar);
        });
    }

    void GLFWAPI_EventReceiver::PollEvents()
    {
        glfwWaitEvents();
    }

    void GLFWAPI_EventReceiver::SetCallbackWindow(const Ref<TE::Core::IWindow>& window, const TE::Events::EventCallback & eventsCallback)
    {
        s_Window = window;
        s_EventCallback = eventsCallback;
        SetCallBacks();
    }

}