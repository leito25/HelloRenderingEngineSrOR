cmake_minimum_required(VERSION 3.20)

project(RenderingEngineDemo LANGUAGES C CXX)

set(BuildSystem ../dependencies/sequoia/build_system)
set(DemoDir ../Demo)





add_executable(Demo DemoMain.cpp)

target_sources(Demo PRIVATE)

target_include_directories(Demo PRIVATE ${DemoDir})

add_subdirectory(../dependencies/glfw glfw)
target_link_libraries(Demo PRIVATE glfw)
target_include_directories(Demo PRIVATE ../dependencies/glfw/include)



