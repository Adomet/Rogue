#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Rogue {

	class ROGUE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}

// Core log macros
#define RG_CORE_TRACE(...)    ::Rogue::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RG_CORE_INFO(...)     ::Rogue::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RG_CORE_WARN(...)     ::Rogue::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RG_CORE_ERROR(...)    ::Rogue::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RG_CORE_FATAL(...)    ::Rogue::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define RG_TRACE(...)	      ::Rogue::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RG_INFO(...)	      ::Rogue::Log::GetClientLogger()->info(__VA_ARGS__)
#define RG_WARN(...)	      ::Rogue::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RG_ERROR(...)	      ::Rogue::Log::GetClientLogger()->error(__VA_ARGS__)
#define RG_FATAL(...)	      ::Rogue::Log::GetClientLogger()->fatal(__VA_ARGS__)