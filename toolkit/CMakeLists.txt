project(toolkit)
add_executable(toolkit src/main.cpp)
target_link_libraries(toolkit -lGL ${GL_LIBRARY} ${SDL2_LIBRARY})