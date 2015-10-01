cmake_minimum_required(VERSION 2.8)

project(Week2)

# Create library
add_library(integrate STATIC simpson.cpp)

# Create executable
add_executable(simpson simpson_main.cpp)
target_link_libraries(simpson integrate)

# Install library
install(TARGETS integrate
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

install(FILES simpson.hpp DESTINATION include)

# Install executable
install(TARGETS simpson DESTINATION bin)
