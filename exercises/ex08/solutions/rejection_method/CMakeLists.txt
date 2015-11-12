cmake_minimum_required(VERSION 2.8)

project(AcceptanceRejectionMethod)

set(CMAKE_CXX_FLAGS "-std=c++0x")

# Create executable
add_executable(distribution_test main.cpp)

# Install executable
install(TARGETS distribution_test DESTINATION bin)
install(FILES plot.py repeat_test DESTINATION bin)
