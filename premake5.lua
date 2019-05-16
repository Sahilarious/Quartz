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



include "Quartz/vendor/GLFW"
include "Quartz/vendor/Glad"
include "Quartz/vendor/imgui"
 
project "Quartz"
    location "Quartz"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "qzpch.h"
    pchsource "Quartz/src/qzpch.cpp"

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
        "%{IncludeDir.Imgui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "Imgui",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "QZ_PLATFORM_WINDOWS",
            "QZ_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "QZ_DEBUG"
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "QZ_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "QZ_DIST"
        buildoptions "/MD"
        optimize "On"

project "Sandbox"
   location "Sandbox"
   kind "ConsoleApp"
   language "C++"

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
       "Quartz/src"
   }

   links
   {
       "Quartz"
   }

   filter "system:windows"
       cppdialect "C++17"
       staticruntime "On"
       systemversion "latest"

       defines
       {
           "QZ_PLATFORM_WINDOWS"
       }

   filter "configurations:Debug"
       defines "QZ_DEBUG"
       buildoptions "/MDd"
       symbols "On"

   filter "configurations:Release"
       defines "QZ_RELEASE"
       buildoptions "/MD"
       optimize "On"

   filter "configurations:Dist"
       defines "QZ_DIST"
       buildoptions "/MD"
       optimize "On"


