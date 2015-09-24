cmake_minimum_required(VERSION 2.8)
 
project(Square)

 # Just compile the square program from both source files
add_executable(square1 main.cpp square.cpp)

#install the programs into the bin subdirectory
install(TARGETS square1 DESTINATION bin)
