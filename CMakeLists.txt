cmake_minimum_required(VERSION 3.1...3.17 FATAL_ERROR)

project(DesolateEngine VERSION 0.1.0)

# dependency subdirectories
add_subdirectory("deps/glad")
add_subdirectory("deps/glfw")
add_subdirectory("deps/glm")

# source subdirectories
add_subdirectory("src")