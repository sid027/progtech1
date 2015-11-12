cmake_minimum_required(VERSION 2.8)

project(ContainerBenchmark)

SET(CMAKE_CXX_FLAGS "-std=c++0x -march=native")

add_executable(containers containers.cpp)

install(TARGETS containers DESTINATION bin)
