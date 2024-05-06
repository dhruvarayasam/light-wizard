cmake_minimum_required(VERSION 3.28.1)
project(GraphicsLib)

add_library(GraphicsLib vec3.h ray.h light.h scene.h camera.h camera.cpp vec3.cpp ray.cpp scene.cpp light.cpp)