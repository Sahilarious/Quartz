workspace "Quartz"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Quartz/vendor/GLFW/include"
IncludeDir["Glad"] = "Quartz/vendor/Glad/include"
IncludeDir["Imgui"] = "Quartz/vendor/imgui"
IncludeDir["glm"] = "Quartz/vendor/glm"



group "Dependencies"
    include "Quartz/vendor/GLFW"
    include "Quartz/vendor/Glad"
    include "Quartz/vendor/imgui"
group ""

project "Quartz"
    location "Quartz"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "qzpch.h"
    pchsource "Quartz/src/qzpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
        "%{prj.name}/vendor/glm/glm/**.hpp",
        "%{prj.name}/vendor/glm/glm/**.inl"
    }

    defines
    {
        "_CRT_SECURE_NO_WARNINGS"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.Imgui}",
        "%{IncludeDir.glm}"
    }

    links
    {
        "GLFW",
        "Glad",
        "Imgui",
        "opengl32.lib"
    }

    filter "system:windows"
        systemversion "latest"

        defines
        {
            "QZ_PLATFORM_WINDOWS",
            "QZ_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

    filter "configurations:Debug"
        defines "QZ_DEBUG"
        runtime "Debug"  -- use staticruntime for static library (multi threaded debug), as opposed to a dynamic linked library (multi threaded debug dll)
        symbols "on"

    filter "configurations:Release"
        defines "QZ_RELEASE"
        runtime "Release"
        optimize "on"

    filter "configurations:Dist"
        defines "QZ_DIST"
        runtime "Release"
        optimize "on"

project "Sandbox"
   location "Sandbox"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   staticruntime "on"

   targetdir ("bin/" .. outputdir .. "/%{prj.name}")
   objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

   
   files
   {
       "%{prj.name}/src/**.h",
       "%{prj.name}/src/**.cpp"
   }

   includedirs
   {
       "Quartz/vendor/spdlog/include",
       "Quartz/src",
       "Quartz/vendor",
       "%{IncludeDir.glm}",
   }

   links
   {
       "Quartz"
   }

   filter "system:windows"
       systemversion "latest"

       defines
       {
           "QZ_PLATFORM_WINDOWS"
       }

   filter "configurations:Debug"
       defines "QZ_DEBUG"
       runtime "Debug"
       symbols "on"

   filter "configurations:Release"
       defines "QZ_RELEASE"
       runtime "Release"
       optimize "on"

   filter "configurations:Dist"
       defines "QZ_DIST"
       runtime "Release"
       optimize "on"


