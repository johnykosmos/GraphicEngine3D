cmake_minimum_required(VERSION 3.16)

project(GraphicEngine3D)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory("dependencies/glad")
add_subdirectory("dependencies/glfw")
add_subdirectory("dependencies/glm")
add_subdirectory("dependencies/stb_image")
add_subdirectory("Engine")
