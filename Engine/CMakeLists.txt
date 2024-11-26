cmake_minimum_required(VERSION 3.16)

project(Engine)

add_library(
    Engine STATIC
    # ADD MORE PATHS IN SRC/
    core/Window.cpp
    core/Engine.cpp
    core/Application.cpp
)

target_include_directories(Engine PUBLIC core)

target_link_libraries(Engine PUBLIC glfw)
target_link_libraries(Engine PUBLIC glad)

find_package(OpenGL REQUIRED)
target_link_libraries(Engine PUBLIC OpenGL::GL)
