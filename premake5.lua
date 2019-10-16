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


group "Dependencies"
    include "Quartz/vendor/GLFW"
    include "Quartz/vendor/Glad"
    include "Quartz/vendor/imgui"
group ""

project "Quartz"
    location "Quartz"
    kind "SharedLib"
    language "C++"
    staticruntime "off"

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
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox\"")
        }

    filter "configurations:Debug"
        defines "QZ_DEBUG"
        runtime "Debug"  -- use staticruntime for static library (multi threaded debug), as opposed to a dynamic linked library (multi threaded debug dll)
        symbols "On"

    filter "configurations:Release"
        defines "QZ_RELEASE"
        runtime "Release"
        optimize "On"

    filter "configurations:Dist"
        defines "QZ_DIST"
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
       "Quartz/vendor/spdlog/include",
       "Quartz/src"
   }

   links
   {
       "Quartz"
   }

   filter "system:windows"
       cppdialect "C++17"
       systemversion "latest"

       defines
       {
           "QZ_PLATFORM_WINDOWS"
       }

   filter "configurations:Debug"
       defines "QZ_DEBUG"
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines "QZ_RELEASE"
       runtime "Release"
       optimize "On"

   filter "configurations:Dist"
       defines "QZ_DIST"
       runtime "Release"
       optimize "On"


