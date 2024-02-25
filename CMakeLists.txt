cmake_minimum_required(VERSION 3.23)
project(GLTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(GLTest main.cpp )
add_executable(CC main2.cpp)
target_link_libraries(GLTest -lglew32 -lopengl32 -lfreeglut -lglu32 )
