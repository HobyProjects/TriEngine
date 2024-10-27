#include "GL_Context.hpp"
#include "Asserts.hpp"


namespace TE::APIs::OpenGL
{
    GL_Context::GL_Context(GLFWwindow* window): m_Window(window)
    {
    }

    Boolean GL_Context::MakeContextCurrent()
    {
        TRIMANA_ASSERT(m_Window, "GL_Context::MakeContextCurrent: m_Window is null");
        glfwMakeContextCurrent(m_Window);
        glfwSwapInterval(1);

        GLenum status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
        if(status == NULL)
        {
            TE_CORE_CRITICAL("GL_Context::MakeContextCurrent: Failed to initialize GLAD");
            return TE_FALSE;
        }

        TE_CORE_INFO("GL_Context::MakeContextCurrent: Created");
        return TE_TRUE;
    }

    void GL_Context::SwapBuffers()
    {
        TRIMANA_ASSERT(m_Window, "GL_Context::SwapBuffers: m_Window is null");
        glfwSwapBuffers(m_Window);
    }

    void GL_Context::ChangeSwapInterval(UInt32 interval)
    {
        TRIMANA_ASSERT(m_Window, "GL_Context::ChangeSwapInterval: m_Window is null");
        glfwSwapInterval(interval);
    }
}