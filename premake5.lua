workspace "Rogue"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder(solution dir)
IncludeDir ={}
IncludeDir["GLFW"] = "Rogue/vendor/GLFW/include"
IncludeDir["Glad"] = "Rogue/vendor/Glad/include"
IncludeDir["ImGui"] = "Rogue/vendor/imgui"

include "Rogue/vendor/GLFW"
include "Rogue/vendor/Glad"
include "Rogue/vendor/imgui"

startproject "Sandbox"


project "Rogue"
	location "Rogue"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "rgpch.h"
	pchsource "Rogue/src/rgpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RG_PLATFORM_WINDOWS",
			"RG_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "RG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RG_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "RG_DIST"
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Rogue/vendor/spdlog/include",
		"Rogue/src"
	}

	links
	{
		"Rogue"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"RG_PLATFORM_WINDOWS"
		}

    filter "configurations:Debug"
		defines "RG_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RG_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "RG_DIST"
		runtime "Release"
		optimize "On"