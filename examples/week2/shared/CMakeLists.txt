cmake_minimum_required(VERSION 2.8)
 
project(Square)

# Make a shared library for the square function
add_library(square SHARED ../square.cpp)

# Now compile just the main function and link it against the dynamic library
add_executable(square3 ../main.cpp)
target_link_libraries(square3 square)

#install the programs into the bin subdirectory
install(TARGETS square3 DESTINATION bin)

#install the libraries into lib or bin, dependent on platform
install(TARGETS square
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
       )

#install the headers into include
install(FILES ../square.hpp DESTINATION include)



