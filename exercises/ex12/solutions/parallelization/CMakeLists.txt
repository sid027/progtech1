cmake_minimum_required( VERSION 2.8 )

project(openMP)

set(CMAKE_CXX_FLAGS "-Wall -fopenmp")
set(CMAKE_BUILD_TYPE RELEASE)

add_executable(simpson main.cpp)

install(TARGETS simpson DESTINATION bin)
