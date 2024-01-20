cmake_minimum_required(VERSION 3.28.1)
project(LightWizard VERSION 0.1) # version number and project title
include(CTest)


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
add_subdirectory(lib/operations_lib)
add_subdirectory(lib/geometry_lib)
add_subdirectory(lib/graphics_lib)

target_link_libraries(LightWizard PUBLIC OperationsLib)
target_link_libraries(LightWizard PUBLIC GeometryLib)
target_link_libraries(LightWizard PUBLIC GraphicsLib)



target_include_directories(OperationsLib PUBLIC
							"${PROJECT_BINARY_DIR}"
							"${PROJECT_SOURCE_DIR}/lib/operations_lib")

target_include_directories(GeometryLib PUBLIC
							"${PROJECT_BINARY_DIR}"
							"${PROJECT_SOURCE_DIR}/lib/geometry_lib")

target_include_directories(GraphicsLib PUBLIC
							"${PROJECT_BINARY_DIR}"
							"${PROJECT_SOURCE_DIR}/lib/graphics_lib")


# binaries for testing

# vector testing
add_executable(operator_overloads ${PROJECT_SOURCE_DIR}/tests/src/vec_tests/op_overl_test.cpp)
target_link_libraries(operator_overloads GraphicsLib GeometryLib OperationsLib)

set_target_properties(operator_overloads
    PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/tests/exec/vec_tests")

enable_testing()

add_test(
	NAME operator_overloads
	COMMAND ${PROJECT_SOURCE_DIR}/tests/exec/vec_tests/operator_overloads
)