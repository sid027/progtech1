cmake_minimum_required(VERSION 2.8)
 
project(Square)

# Make a static library for the square function
add_library(square STATIC ../square.cpp)

# Now compile just the main function and link it against the static library
add_executable(square2 ../main.cpp)
target_link_libraries(square2 square)

# Install the library, header, and programs


#install the programs into the bin subdirectory
install(TARGETS square2 DESTINATION bin)

#install the libraries into lib or bin, dependent on platform
install(TARGETS square
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
       )

#install the headers into include
install(FILES ../square.hpp DESTINATION include)



