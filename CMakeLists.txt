# I really don't know CMake so I don't know if this is a good idea to use. 
cmake_minimum_required(VERSION 2.6)
project(toolkit)

# set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PixelandToolkit_SOURCE_DIR}/cmake")
set(BIN_DIR ${PixelandToolkit_SOURCE_DIR}/bin)

set(GL_INCLUDE_PATH /usr/include/GL)
set(SDL2_INCLUDE_DIR /usr/include/SDL2)
set(GL_LIBRARY /usr/lib/i386-linux-gnu/libGLU.so)
set(SDL2_LIBRARY /usr/lib/i386-linux-gnu/libSDL2-2.0.so)

include_directories(${GL_INCLUDE_PATH} ${SDL2_INCLUDE_DIR})

add_subdirectory(toolkit)