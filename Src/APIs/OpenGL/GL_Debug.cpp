#include "GL_Debug.hpp"

namespace TE::APIs::OpenGL
{
    #ifdef TRIMANA_DEBUG
        void GLAPIENTRY DebugMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam)
        {       
            const char* type_str        = nullptr;
            const char* severity_str    = nullptr;
            const char* source_str      = nullptr;
            
            switch(type)
            {
                case GL_DEBUG_TYPE_ERROR:                   type_str = TRIMANA_MACTOSTRING(GL_DEBUG_TYPE_ERROR); break;
                case GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR:     type_str = TRIMANA_MACTOSTRING(GL_DEBUG_TYPE_DEPRECATED_BEHAVIOR); break;
                case GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR:      type_str = TRIMANA_MACTOSTRING(GL_DEBUG_TYPE_UNDEFINED_BEHAVIOR); break;
                case GL_DEBUG_TYPE_PORTABILITY:             type_str = TRIMANA_MACTOSTRING(GL_DEBUG_TYPE_PORTABILITY); break;
                case GL_DEBUG_TYPE_PERFORMANCE:             type_str = TRIMANA_MACTOSTRING(GL_DEBUG_TYPE_PERFORMANCE); break;
                case GL_DEBUG_TYPE_MARKER:                  type_str = TRIMANA_MACTOSTRING(GL_DEBUG_TYPE_MARKER); break;
                case GL_DEBUG_TYPE_PUSH_GROUP:              type_str = TRIMANA_MACTOSTRING(GL_DEBUG_TYPE_PUSH_GROUP); break;
                case GL_DEBUG_TYPE_POP_GROUP:               type_str = TRIMANA_MACTOSTRING(GL_DEBUG_TYPE_POP_GROUP); break;
                case GL_DEBUG_TYPE_OTHER:                   type_str = TRIMANA_MACTOSTRING(GL_DEBUG_TYPE_OTHER); break;
                default:                                    type_str = "GL_DEBUG_TYPE_UNKNOWN"; break;
            }
            
            switch(severity)
            {
                case GL_DEBUG_SEVERITY_HIGH:         severity_str = TRIMANA_MACTOSTRING(GL_DEBUG_SEVERITY_HIGH); break;
                case GL_DEBUG_SEVERITY_MEDIUM:       severity_str = TRIMANA_MACTOSTRING(GL_DEBUG_SEVERITY_MEDIUM); break;
                case GL_DEBUG_SEVERITY_LOW:          severity_str = TRIMANA_MACTOSTRING(GL_DEBUG_SEVERITY_LOW); break;
                case GL_DEBUG_SEVERITY_NOTIFICATION: severity_str = TRIMANA_MACTOSTRING(GL_DEBUG_SEVERITY_NOTIFICATION); break;
                default:                             severity_str = "GL_DEBUG_SEVERITY_UNKNOWN"; break;
            }

            switch(source)
            {
                case GL_DEBUG_SOURCE_API:             source_str = TRIMANA_MACTOSTRING(GL_DEBUG_SOURCE_API); break;
                case GL_DEBUG_SOURCE_WINDOW_SYSTEM:   source_str = TRIMANA_MACTOSTRING(GL_DEBUG_SOURCE_WINDOW_SYSTEM); break;
                case GL_DEBUG_SOURCE_SHADER_COMPILER: source_str = TRIMANA_MACTOSTRING(GL_DEBUG_SOURCE_SHADER_COMPILER); break;
                case GL_DEBUG_SOURCE_THIRD_PARTY:     source_str = TRIMANA_MACTOSTRING(GL_DEBUG_SOURCE_THIRD_PARTY); break;
                case GL_DEBUG_SOURCE_APPLICATION:     source_str = TRIMANA_MACTOSTRING(GL_DEBUG_SOURCE_APPLICATION); break;
                case GL_DEBUG_SOURCE_OTHER:           source_str = TRIMANA_MACTOSTRING(GL_DEBUG_SOURCE_OTHER); break;
                default:                              source_str = "GL_DEBUG_SOURCE_UNKNOWN"; break;
            }

            TE_CORE_CRITICAL("<---------< GL DEBUG MESSAGE >--------->");
            TE_CORE_CRITICAL(" -> ID:         {0}", id);
            TE_CORE_CRITICAL(" -> SOURCE:     {0}", source_str);
            TE_CORE_CRITICAL(" -> TYPE:       {0}", type_str);
            TE_CORE_CRITICAL(" -> SEVERITY:   {0}", severity_str);
            TE_CORE_CRITICAL(" -> MESSAGE:    {0}", message);
            TE_CORE_CRITICAL("<------------------------------------------>");

            if(severity == GL_DEBUG_SEVERITY_HIGH)
                TRIMANA_DEBUGBREAK();
        }

    #endif
}