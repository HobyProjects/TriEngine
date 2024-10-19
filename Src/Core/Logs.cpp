#include "Logs.hpp"
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace TE::Core
{
    static bool s_Initialized = false;
    static std::shared_ptr<spdlog::logger> s_CoreLogger = nullptr;
    static std::shared_ptr<spdlog::logger> s_ClientLogger = nullptr;

    void LogSystem::Init()
    {
        std::vector<spdlog::sink_ptr> log_skin{};
        log_skin.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>());
        log_skin.emplace_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>("TE.log", true));
        log_skin[0]->set_pattern("%^[%T] %n: %v%$");
        log_skin[1]->set_pattern("[%T][%l] %n: %v");

        s_CoreLogger = std::make_shared<spdlog::logger>("TE:Core", std::begin(log_skin), std::end(log_skin));
        spdlog::register_logger(s_CoreLogger);
        s_CoreLogger->set_level(spdlog::level::trace);
        s_CoreLogger->flush_on(spdlog::level::trace);

        s_ClientLogger = std::make_shared<spdlog::logger>("TE:Client", std::begin(log_skin), std::end(log_skin));
        spdlog::register_logger(s_ClientLogger);
        s_ClientLogger->set_level(spdlog::level::trace);
        s_ClientLogger->flush_on(spdlog::level::trace);
        s_Initialized = true;
    }

    std::shared_ptr<spdlog::logger>& LogSystem::GetCoreLogger() 
    {
        if(!s_Initialized)
            Init();

        return s_CoreLogger;
    }

    std::shared_ptr<spdlog::logger>& LogSystem::GetClientLogger() 
    {
        if(!s_Initialized)
            Init();

        return s_ClientLogger;
    }
}