#pragma once

#include <memory>

#pragma warning(push, 0)
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)

namespace TE::Core
{
    /**
     * @brief The LogSystem class is a wrapper around spdlog to initialize and use loggers in the Trimana Engine.
     */
    class LogSystem
    {
        public:
            /**
             * @brief Initializes the loggers to use in the Trimana Engine.
             */
            static void Init();

            /**
             * @brief Returns the core logger of the Trimana Engine.
             * @return The core logger of the Trimana Engine.
             */
            static std::shared_ptr<spdlog::logger>& GetCoreLogger();

            /**
             * @brief Returns the client logger of the Trimana Engine.
             * @return The client logger of the Trimana Engine.
             */
            static std::shared_ptr<spdlog::logger>& GetClientLogger();
    };

}

// Core logger
#define TE_CORE_TRACE(...)    ::TE::Core::LogSystem::GetCoreLogger()->trace(__VA_ARGS__)
#define TE_CORE_INFO(...)     ::TE::Core::LogSystem::GetCoreLogger()->info(__VA_ARGS__)
#define TE_CORE_WARN(...)     ::TE::Core::LogSystem::GetCoreLogger()->warn(__VA_ARGS__)
#define TE_CORE_ERROR(...)    ::TE::Core::LogSystem::GetCoreLogger()->error(__VA_ARGS__)
#define TE_CORE_CRITICAL(...) ::TE::Core::LogSystem::GetCoreLogger()->critical(__VA_ARGS__)

// Client logger
#define TE_TRACE(...)    ::TE::Core::LogSystem::GetClientLogger()->trace(__VA_ARGS__)
#define TE_INFO(...)     ::TE::Core::LogSystem::GetClientLogger()->info(__VA_ARGS__)
#define TE_WARN(...)     ::TE::Core::LogSystem::GetClientLogger()->warn(__VA_ARGS__)
#define TE_ERROR(...)    ::TE::Core::LogSystem::GetClientLogger()->error(__VA_ARGS__)
#define TE_CRITICAL(...) ::TE::Core::LogSystem::GetClientLogger()->critical(__VA_ARGS__)