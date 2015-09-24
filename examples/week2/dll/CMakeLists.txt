cmake_minimum_required(VERSION 2.8)
 
project(Square)

# set version numbers

set(Square_VERSION_MAJOR 1)
set(Square_VERSION_MINOR 0)

# use version numbers in a header file
# the file needs to be configured, that is created from an input file
# with values of variables replaced

configure_file (
  "${PROJECT_SOURCE_DIR}/version.cpp.in"
  "${PROJECT_BINARY_DIR}/version.cpp"
  )



# Allow the user to set an option whether to build static or dynamic

option(BUILD_SQUARE_SHARED "Build the square library shared." ON)

if(BUILD_SQUARE_SHARED)
  set(SQUARE_LIBRARY_TYPE SHARED)
else(BUILD_SQUARE_SHARED)
  set(SQUARE_LIBRARY_TYPE STATIC)
endif(BUILD_SQUARE_SHARED)

include_directories(${PROJECT_SOURCE_DIR})
add_library(square ${SQUARE_LIBRARY_TYPE} square.cpp ${PROJECT_BINARY_DIR}/version.cpp)

if (MSVC AND BUILD_SQUARE_SHARED)
  set_target_properties(square PROPERTIES COMPILE_DEFINITIONS BUILD_DLL=1)
endif (MSVC AND BUILD_SQUARE_SHARED)


# Now compile just the main function and link it against the library
add_executable(square5 main.cpp)
target_link_libraries(square5 square)

#install the programs into the bin subdirectory
install(TARGETS square5 DESTINATION bin)

#install the libraries into lib or bin, dependent on platform
install(TARGETS square
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin
       )

#install the headers into include
install(FILES square.hpp DESTINATION include)



