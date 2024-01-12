cmake_minimum_required(VERSION 3.28.1)
project(GraphicsLib)

add_library(GraphicsLib camera.h vec3.h ray.h camera.cpp vec3.cpp ray.cpp)