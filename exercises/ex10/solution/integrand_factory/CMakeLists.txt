cmake_minimum_required(VERSION 2.8)

project(SimpsonIntegrationUsingAbstractClass)

set(CMAKE_CXX_FLAGS "-Wall -std=c++0x")

# Create executable
add_executable(simpson main.cpp)

# Install executable
install(TARGETS simpson DESTINATION bin)
