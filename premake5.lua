-- premake5.lua
-- local project_location = path.getabsolute("/")

--Solution important settings

newoption {
   trigger = "2020",
   description = "Opens 2020 solution"
}

newoption {
   trigger = "2021",
   description = "Opens 2021 solution"
}
 
newoption {
   trigger = "2022",
   description = "Opens 2022 solution"
}

local workspace_name = "Advent_Of_Code"
project_platform = {"x64"}


--Projects global settings
local languague = "C++"
local projects_location = "build"

--Diferent projects


project_name = {"day01","day02","day03","day04","day05",
                "day06","day07","day08","day09","day10",
                "day11","day12","day13","day14","day15",
                "day16","day17","day18","day19","day20",
                "day21","day22","day23","day24","day25"}

--Variables 
local i = 1
if _OPTIONS["2021"] then

   workspace(workspace_name .. "2021")
      cppdialect "C++11"
      startproject (project_name[1])
      configurations ({ "Debug", "Release" })
      location (projects_location .. "/2021")
      platforms {"x64"}

      includedirs {"./include/",
                  "./src/" 
                  }
      files{"./src/*.cpp",
      "./include/*.h"}

      defines {
         "_CRT_SECURE_NO_WARNINGS"
      }

  
      for _,i in ipairs(project_name) do


         project (i)
   
            location (projects_location .. "/2021" .. "/" .. i)
            kind ("ConsoleApp")
            language (languague)
            targetdir "bin/%{cfg.buildcfg}"
   
            files {("./days/2021/" .. i .. "/**.cpp"), "./days/2021/" .. i .. "/**.txt"}
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
    end

    if _OPTIONS["2022"] then

      workspace(workspace_name .. "2022")
      cppdialect "C++11"
      startproject (project_name[1])
      configurations ({ "Debug", "Release" })
      location (projects_location .. "/2022")
      platforms {"x64"}

      includedirs {"./include/",
                  "./src/" 
                  }
      files{"./src/*.cpp",
      "./include/*.h"}

      defines {
         "_CRT_SECURE_NO_WARNINGS"
      }

      for _,i in ipairs(project_name) do

         project (i)
   
            location (projects_location .. "/2022" .. "/" .. i)
            kind ("ConsoleApp")
            language (languague)
            targetdir "bin/%{cfg.buildcfg}"
   
            files {("./days/2022/" .. i .. "/**.cpp"), "./days/2022/" .. i .. "/**.txt"}
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
    end


    if _OPTIONS["2020"] then

      workspace(workspace_name .. "2020")
      cppdialect "C++11"
      startproject (project_name[1])
      configurations ({ "Debug", "Release" })
      location (projects_location .. "/2020")
      platforms {"x64"}

      includedirs {"./include/",
                  "./src/" 
                  }
      files{"./src/*.cpp",
      "./include/*.h"}

      defines {
         "_CRT_SECURE_NO_WARNINGS"
      }

      for _,i in ipairs(project_name) do

         project (i)
   
            location (projects_location .. "/2020" .. "/" .. i)
            kind ("ConsoleApp")
            language (languague)
            targetdir "bin/%{cfg.buildcfg}"
   
            files {("./days/2020/" .. i .. "/**.cpp"), "./days/2020/" .. i .. "/**.txt"}
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
    end

