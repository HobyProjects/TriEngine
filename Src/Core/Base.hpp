#pragma once

#ifdef TRIMANA_DEBUG

    // Define a debug break macro for Windows using __debugbreak()
    #if defined(TRIMANA_PLATFORM_WINDOWS)
        #define TRIMANA_DEBUGBREAK() __debugbreak()
    
    // Define a debug break macro for Linux using raise(SIGTRAP)
    #elif defined(TRIMANA_PLATFORM_LINUX)
        #include <signal.h>
        #define TRIMANA_DEBUGBREAK() raise(SIGTRAP)
    
    // Display an error message if the platform does not support debugbreak
    #else
        #error "Platform doesn't support debugbreak yet!"
    #endif

    // Enable instruments for debugging
    #define TRIMANA_INSTRUMENTS_ENABLED

    // Enable asserts for debugging
    #define TRIMANA_ASSERTS_ENABLED

    // Macro to convert a value to a string
    #define TRIMANA_MACTOSTRING(x) #x

    // Macro to set a bit at a specific position
    #define TE_BIT(x) (1 << x)

#else

    #define TRIMANA_DEBUGBREAK()
    #define TRIMANA_MACTOSTRING(x) #x

#endif // TRIMANA_DEBUG