cmake_minimum_required(VERSION 3.16)

project(Engine)

add_library(
    Engine STATIC
    core/Engine.cpp
    core/Application.cpp
    graphics/Renderer.cpp
    graphics/Camera.cpp
    graphics/Mesh.cpp
    graphics/objects/TransformableObject.cpp
    graphics/objects/shapes/CubeShape.cpp
    platform/io/Window.cpp
    platform/io/Keys.cpp
    platform/io/Input.cpp
    platform/opengl/GLBuffers.cpp
    platform/opengl/VertexLayout.cpp
    platform/opengl/VertexArray.cpp
    platform/opengl/Shader.cpp
    platform/opengl/Texture.cpp
)

target_include_directories(
    Engine PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/core
    ${CMAKE_CURRENT_SOURCE_DIR}/graphics
    ${CMAKE_CURRENT_SOURCE_DIR}/graphics/objects
    ${CMAKE_CURRENT_SOURCE_DIR}/graphics/objects/shapes
    ${CMAKE_CURRENT_SOURCE_DIR}/platform/io
    ${CMAKE_CURRENT_SOURCE_DIR}/platform/opengl
)


target_link_libraries(Engine PUBLIC glfw)
target_link_libraries(Engine PUBLIC glad)
target_link_libraries(Engine PUBLIC stb_image)

find_package(OpenGL REQUIRED)
target_link_libraries(Engine PUBLIC OpenGL::GL)
