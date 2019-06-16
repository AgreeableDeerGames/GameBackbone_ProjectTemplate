# CMakeLists for ProjectTemplate library

cmake_minimum_required (VERSION 3.8)
add_library(ProjectTemplate SHARED
  "include/ProjectTemplate/Core/EventController.h"
  "include/ProjectTemplate/Utils/DllUtils.h"
  "include/ProjectTemplate.h"
  
  "source/Core/EventController.cpp"
  "source/ProjectTemplate.cpp"
)
set_target_properties(ProjectTemplate PROPERTIES DEBUG_POSTFIX ${CMAKE_DEBUG_POSTFIX})

# GameBackbone has these as public targets. This means that they are automatically
# added to the target_link_libraries for ProjectTemplate
# ProjectTemplate still needs to find the packages for GB to link against though.
find_package(SFML 2 COMPONENTS network audio graphics window system)
find_package(TGUI 0.8.2 REQUIRED)

find_package(GameBackbone 0.2.1 REQUIRED) 
target_link_libraries(ProjectTemplate PUBLIC GameBackbone) 

message("current source dir: ${CMAKE_CURRENT_SOURCE_DIR}")

target_include_directories(ProjectTemplate PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")