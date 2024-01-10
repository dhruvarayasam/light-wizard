cmake_minimum_required(VERSION 3.28.1)
project(LightWizard VERSION 0.1) # version number and project title

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

configure_file(include/Config.h.in
	"${CMAKE_CURRENT_SOURCE_DIR}/include/Config.h")

# Include directories
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)


# Add executable
add_executable(LightWizard ${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp)

set_target_properties(LightWizard
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin")


# Library directories
add_subdirectory(lib/rays)

target_link_libraries(LightWizard PUBLIC RayLib)

target_include_directories(RayLib PUBLIC
							"${PROJECT_BINARY_DIR}"
							"${PROJECT_SOURCE_DIR}/lib/rays")


