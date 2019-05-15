#pragma once


#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/fmt/ostr.h"

namespace Quartz
{

	class QUARTZ_API Log
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

// Core Log Macros
#define QZ_CORE_TRACE(...)    ::Quartz::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define QZ_CORE_INFO(...)     ::Quartz::Log::GetCoreLogger()->info(__VA_ARGS__)
#define QZ_CORE_WARN(...)     ::Quartz::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define QZ_CORE_ERROR(...)    ::Quartz::Log::GetCoreLogger()->error(__VA_ARGS__)
#define QZ_CORE_FATAL(...)    ::Quartz::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Log Macros
#define QZ_TRACE(...)         ::Quartz::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define QZ_INFO(...)          ::Quartz::Log::GetCoreLogger()->info(__VA_ARGS__)
#define QZ_WARN(...)          ::Quartz::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define QZ_ERROR(...)         ::Quartz::Log::GetCoreLogger()->error(__VA_ARGS__)
#define QZ_FATAL(...)         ::Quartz::Log::GetCoreLogger()->fatal(__VA_ARGS__)
