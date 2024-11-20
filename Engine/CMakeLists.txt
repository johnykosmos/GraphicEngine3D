cmake_minimum_required(VERSION 3.31)

project(Engine)

add_library(
    Engine STATIC
    # ADD MORE PATHS IN SRC/
)

target_include_directories(Engine PUBLIC "headers")

target_link_libraries(Engine PUBLIC glfw)
target_link_libraries(Engine PUBLIC glad)
