#pragma once

#include <filesystem>

#include "Logs.hpp"
#include "Base.hpp"

#ifdef TRIMANA_ASSERTS_ENABLED
    #define TRIMANA_ASSERT(condition, ...) if(!(condition)) { TE_CORE_CRITICAL("Assertion failed: {0}", __VA_ARGS__); TRIMANA_DEBUGBREAK(); }
#else
    #define TRIMANA_ASSERT(condition, ...)
#endif