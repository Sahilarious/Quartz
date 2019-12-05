project "Glad"
    kind "StaticLib"
    language "C"
    staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c",
    }

    includedirs
    {
        "include"
    }

    filter "system:windows"
        systemversion "latest"


    filter "configurations:Debug"
        runtime "Debug"  -- use staticruntime for static library (multi threaded debug), as opposed to a dynamic linked library (multi threaded debug dll)
        symbols "on"

    filter "configurations:Release"
        runtime "Release"
        optimize "on"

