project "ImGui"
   kind "StaticLib"
   language "C++"
   cppdialect "C++20"
   staticruntime "off"

   files 
   {
      "Source/imgui.cpp",
      "Source/imgui_demo.cpp", 
      "Source/imgui_draw.cpp",
      "Source/imgui_tables.cpp",
      "Source/imgui_widgets.cpp",
      "Source/backends/imgui_impl_opengl3.cpp",
      "Source/backends/imgui_impl_glfw.cpp"
   }

   includedirs 
   {
      "Source",
      "Source/backends"
   }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:linux"
       pic "On"

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"

   filter "configurations:Release"
       defines { "RELEASE" } 
       runtime "Release"
       optimize "On"

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"
