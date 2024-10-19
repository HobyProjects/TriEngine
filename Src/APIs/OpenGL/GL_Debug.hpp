#pragma once

#include <glad/glad.h>
#include <Asserts.hpp>

namespace TE::APIs::OpenGL
{
    #ifdef TRIMANA_DEBUG
        /**
         * @brief Callback function for handling OpenGL debug messages
         *
         * This function is called when an OpenGL debug message is generated.
         * It provides information about the source, type, ID, severity, length,
         * message, and user parameter associated with the debug message.
         *
         * @param source The source of the debug message
         * @param type The type of the debug message
         * @param id The ID of the debug message
         * @param severity The severity of the debug message
         * @param length The length of the debug message
         * @param message The debug message string
         * @param userParam The user parameter associated with the debug message
         */
        void GLAPIENTRY DebugMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
    #endif
}