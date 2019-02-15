#pragma once

#ifdef RG_PLATFORM_WINDOWS
	#ifdef RG_BUILD_DLL
		#define ROGUE_API __declspec(dllexport)
	#else
		#define ROGUE_API __declspec(dllimport)
	#endif
#else
	#error Hazel only supports Windows!
#endif

#ifdef RG_DEBUG
	#define RG_ENABLE_ASSERTS
#endif

#ifdef RG_ENABLE_ASSERTS
	#define RG_ASSERT(x, ...) { if(!(x)) {RG_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak(); } }
	#define RG_CORE_ASSERTS(x, ...) {if(!(x)) {RG_CORE_ERROR("Assertion Failed: {0}",__VA_ARGS__); __debugbreak();}
#else
	#define RG_ASSERT(x, ...)
	#define RG_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define RG_BIND_EVENT_FN(fn) std::bind(&fn,this,std::placeholders::_1)