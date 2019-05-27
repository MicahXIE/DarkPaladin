cmake_minimum_required(VERSION 3.5)
project(find_number_of_islands)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES solution.cpp)
add_executable(solution ${SOURCE_FILES})


# usage:
# $> cmake .
# $> make