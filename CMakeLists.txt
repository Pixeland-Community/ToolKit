cmake_minimum_required(VERSION 2.8)

project(Pixeland-Toolkit)


include_directories(${CMAKE_SOURCE_DIR}/glfw/include)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(glfw)



set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)



file(GLOB_RECURSE SRC
    "src/*.cpp"
    "src/*.h"
    "src/*.hpp"
)



add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} GL glfw)



# Enable C++ 11
if (NOT UNIX)
	set_target_properties(${PROJECT_NAME} PROPERTIES
	    CXX_STANDARD 11
	    CXX_STANDARD_REQUIRED ON
	    CXX_EXTENSIONS OFF
	)
else()
	add_definitions(-std=c++11)
endif()
