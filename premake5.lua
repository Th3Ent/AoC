-- premake5.lua
-- local project_location = path.getabsolute("/")

--Solution important settings
local workspace_name = "Advent_Of_Code"
project_platform = {"x64"}


--Projects global settings
local languague = "C++"
local projects_location = "build"

--Diferent projects

local folder_project_name = "2021/"

project_name = {"day01","day02","day03","day04","day05",
                "day06","day07","day08","day09","day10",
                "day11","day12","day13","day14","day15",
                "day16","day17","day18","day19","day20",
                "day21","day22","day23","day24","day25"}

--Variables 
local i = 1

workspace(workspace_name)
   cppdialect "C++11"
   startproject (project_name[1])
   configurations ({ "Debug", "Release" })
   location (projects_location)
   platforms {"x64"}

   includedirs {"./include/",
                "./src/" 
               }
   files{"./src/*.cpp",
   "./include/*.h"}

   defines {
      "_CRT_SECURE_NO_WARNINGS"
   }
      --------------------------------------------------------------------

      ------------------CREATE PROJECT WITH GLFW-------------------------

      --------------------------------------------------------------------

   --------------------------------------------------------------------

   ------------------------MAIN PROJECT--------------------------------

   --------------------------------------------------------------------

   
   for _,i in ipairs(project_name) do


      project (i)

         location (projects_location .. "/" .. i)
         kind ("ConsoleApp")
         language (languague)
         targetdir "bin/%{cfg.buildcfg}"

         files {("./days/2021/" .. i .. "/**.cpp") }
         links {(static_lib_project)}

         filter "configurations:Debug"
            targetdir "bin/%{cfg.buildcfg}"
            defines { "DEBUG","MTR_ENABLED" }
            symbols "On"
            flags {
               "NoPCH",
            }


         filter "configurations:Release"
            targetdir "bin/"
            defines { "NDEBUG" }
            optimize "On"
            
            flags {
               "NoPCH",
            }
         
   end
