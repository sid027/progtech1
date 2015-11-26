cmake_minimum_required(VERSION 2.8)

project(SimpsonConvergence)

set(CMAKE_CXX_FLAGS "-Wall")
set(CMAKE_BUILD_TYPE RELEASE)

# Create library
add_library(integrate STATIC simpson.cpp)

# Create executable
add_executable(simpson main.cpp)
target_link_libraries(simpson integrate)

# Install library
install(TARGETS integrate
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

install(FILES simpson.hpp DESTINATION include)

# Install executable and gnuplot script
install(TARGETS simpson DESTINATION bin)
install(FILES plot.gp DESTINATION bin)
