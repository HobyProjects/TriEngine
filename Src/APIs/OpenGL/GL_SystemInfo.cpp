#include "GL_SystemInfo.hpp"

namespace TE::APIs::OpenGL
{
    String GL_SystemInfo::GetVendor()
    {
        const char* vendor = reinterpret_cast<const char*>(glGetString(GL_VENDOR));
        return String(vendor);
    }

    String GL_SystemInfo::GetRenderer()
    {
        const char* renderer = reinterpret_cast<const char*>(glGetString(GL_RENDERER));
        return String(renderer);
    }

    String GL_SystemInfo::GetVersion()
    {
        const char* version = reinterpret_cast<const char*>(glGetString(GL_VERSION));
        return String(version);
    }

    String GL_SystemInfo::GetGLSLVersion()
    {
        const char* version = reinterpret_cast<const char*>(glGetString(GL_SHADING_LANGUAGE_VERSION));
        char GL_MAJOR = version[0];
        char GL_MINOR = version[2];

        std::stringstream ss;
        ss << "#version " << GL_MAJOR << GL_MINOR << 0 << " core";
        return ss.str();
    }
}