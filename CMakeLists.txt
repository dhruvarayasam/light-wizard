cmake_minimum_required(VERSION 3.12)
project(LightWizard VERSION 0.1) # version number and project title

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )


configure_file(include/Config.h.in
	"${CMAKE_CURRENT_SOURCE_DIR}/include/Config.h")

add_executable(LightWizard
	"${CMAKE_CURRENT_SOURCE_DIR}/src/main.cpp") # generate executable from source directory

set_target_properties(LightWizard
	PROPERTIES
	RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"

)

target_include_directories(LightWizard PUBLIC
	"${CMAKE_CURRENT_SOURCE_DIR}/include")



