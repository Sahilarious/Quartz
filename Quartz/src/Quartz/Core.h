#pragma once


#ifdef QZ_PLATFORM_WINDOWS
#if QZ_DYNAMIC_LINK
	#ifdef QZ_BUILD_DLL
		#define  __declspec(dllexport)
	#else
		#define  __declspec(dllimport)
	#endif
#else 
    #define QUARTZ_API
#endif
#else
	#error Quartz only supports Windows!
#endif

#ifdef QZ_DEBUG
    #define QZ_ENABLE_ASSERTS
#endif

#ifdef QZ_ENABLE_ASSERTS
	#define QZ_ASSERT(x, ...) { if(!(x)) { QZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define QZ_CORE_ASSERT(x, ...) { if(!(x)) { QZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } } 
#else
	#define QZ_ASSERT(x, ...)
	#define QZ_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define QZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)
