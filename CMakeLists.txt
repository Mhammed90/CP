cmake_minimum_required(VERSION 3.23)
project(GLTest)

set(CMAKE_CXX_STANDARD 14)

add_executable(GLTest main.cpp)
add_executable(CC DP.cpp main3.cpp )
add_executable(temp  main3.cpp)
add_executable(Graph  Graph.cpp)
add_executable(A  A.cpp)
add_executable(Math math.cpp)


add_executable(stringProcessing  StringProcessing.cpp)
target_link_libraries(GLTest -lglew32 -lopengl32 -lfreeglut -lglu32 )
