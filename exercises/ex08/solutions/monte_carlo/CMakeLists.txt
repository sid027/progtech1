cmake_minimum_required(VERSION 2.8)

project(PiMonteCarloCalculation)

set(CMAKE_CXX_FLAGS "-std=c++11")

# Create executable
add_executable(random main.cpp)

# Install executable
install(TARGETS random DESTINATION bin)
install(FILES run_script.sh random_plot.py DESTINATION bin)
