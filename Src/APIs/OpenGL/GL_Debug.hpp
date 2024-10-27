#pragma once

#include <glad/glad.h>
#include <Asserts.hpp>

namespace TE::APIs::OpenGL
{
    #ifdef TRIMANA_DEBUG
        void GLAPIENTRY DebugMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);
    #endif
}