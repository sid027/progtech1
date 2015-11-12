cmake_minimum_required( VERSION 2.8 )

project(pt15_week5_task1)

add_executable(simpson main.cpp)

install(TARGETS simpson DESTINATION bin)
