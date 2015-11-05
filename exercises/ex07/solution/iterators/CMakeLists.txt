cmake_minimum_required( VERSION 2.8 )

include_directories( ${CMAKE_HOME_DIRECTORY} )
set(CMAKE_CXX_FLAGS "-Wall -std=c++03")

add_executable(main main.cpp)


