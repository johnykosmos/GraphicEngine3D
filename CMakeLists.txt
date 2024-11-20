cmake_minimum_required(VERSION 3.31)

project(GraphicEngine3D)


add_executable(test)

target_link_libraries(my_app glfw OpenGL::GL)
