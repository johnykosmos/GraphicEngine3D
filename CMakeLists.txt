cmake_minimum_required(VERSION 3.31)

project(GraphicEngine3D)

set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

add_subdirectory("dependencies/glad")
add_subdirectory("dependencies/glfw")
add_subdirectory("Engine")
