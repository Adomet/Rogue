workspace "Rogue"
	architecture "x64"

	configurations
	{
	  "Debug",
	  "Release",
	  "Dist"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Rogue"
	location "Rogue"
	kind "SharedLib"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
	  "%{prj.name}/src/**.h" ,
      "%{prj.name}/src/**.cpp"	
	}
	includedirs
	{
	   "%{prj.name}/src",
		"Rogue/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"


		defines
		{
		 "RG_PLATFORM_WINDOWS",
		 "RG_BUILD_DLL"
		}

		postbuildcommands
		{
		 ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir("bin/" .. outputdir .. "/%{prj.name}")
	objdir("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
	  "%{prj.name}/src/**.h" ,
      "%{prj.name}/src/**.cpp"	
	}
	includedirs
	{
	  "Rogue/vendor/spdlog/include" ,
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
		 "RG_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "HZ_DEBUG"
		symbols "On"
		
	filter "configurations:Release"
		defines "HZ_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "HZ_DIST"
		optimize "On"

