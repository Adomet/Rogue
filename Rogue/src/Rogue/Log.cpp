#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace Rogue {

	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("ROGUE");
		s_CoreLogger->set_level(spdlog::level::trace);

		s_ClientLogger = spdlog::stdout_color_mt("APP");
		s_ClientLogger->set_level(spdlog::level::trace);
	}

}
//Core Log macros
#define RG_CORE_TRACE(...)   ::Rogue::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RG_CORE_INFO(...)    ::Rogue::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RG_CORE_WARN(...)    ::Rogue::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RG_CORE_ERROR(...)   ::Rogue::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RG_CORE_FATAL(...)   ::Rogue::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client Log macros

#define RG_TRACE(...)   ::Rogue::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RG_INFO(...)    ::Rogue::Log::GetClientLogger()->info(__VA_ARGS__)
#define RG_WARN(...)    ::Rogue::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RG_ERROR(...)   ::Rogue::Log::GetClientLogger()->error(__VA_ARGS__)
#define RG_FATAL(...)   ::Rogue::Log::GetClientLogger()->fatal(__VA_ARGS__)
