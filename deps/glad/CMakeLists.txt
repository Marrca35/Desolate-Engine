cmake_minimum_required(VERSION 3.1...3.17 FATAL_ERROR)

project(GLAD)

add_library(glad "src/glad.c")
target_include_directories(glad PRIVATE "include")