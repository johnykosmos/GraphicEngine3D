cmake_minimum_required(VERSION 3.16)

project(Engine)

add_library(
    Engine STATIC
    platform/Window.cpp
    platform/Keys.cpp
    platform/Input.cpp
    core/Engine.cpp
    core/Application.cpp

)

target_include_directories(
    Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${CMAKE_CURRENT_SOURCE_DIR}/platform
)


target_link_libraries(Engine PUBLIC glfw)
target_link_libraries(Engine PUBLIC glad)

find_package(OpenGL REQUIRED)
target_link_libraries(Engine PUBLIC OpenGL::GL)
