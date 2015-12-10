cmake_minimum_required(VERSION 2.8)

project(ExpressionTemplates)

set(CMAKE_CXX_FLAGS "-Wall -save-temps -std=c++11")
set(CMAKE_BUILD_TYPE RELEASE)

# Create executable
add_executable(algorithmic_derivation main.cpp)
add_executable(algorithmic_derivation_bonus main_bonus.cpp)

# Install executable
install(TARGETS algorithmic_derivation DESTINATION bin)
install(TARGETS algorithmic_derivation_bonus DESTINATION bin)
