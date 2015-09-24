cmake_minimum_required(VERSION 2.8)
 
project(Square)

# Allow the user to set an option whether to build static or dynamic

option(BUILD_SQUARE_SHARED "Build the square library shared." ON)

if(BUILD_SQUARE_SHARED)
  set(SQUARE_LIBRARY_TYPE SHARED)
else(BUILD_SQUARE_SHARED)
  set(SQUARE_LIBRARY_TYPE STATIC)
endif(BUILD_SQUARE_SHARED)

add_library(square ${SQUARE_LIBRARY_TYPE} ../square.cpp)


# Now compile just the main function and link it against the library
add_executable(square4 ../main.cpp)
target_link_libraries(square4 square)

#install the programs into the bin subdirectory
install(TARGETS square4 DESTINATION bin)

#install the libraries into lib or bin, dependent on platform
install(TARGETS square
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
       )

#install the headers into include
install(FILES ../square.hpp DESTINATION include)



