# by Jakub Imriska, ITP, ETH Zurich, 2014
# for the lecture Programming Techniques for Scientific Simulations I (HS 14)
# for c++ basics catch-up exercise

cmake_minimum_required(VERSION 2.8)

# you may manually set the compiler if you want
#SET(CMAKE_CXX_COMPILER "g++")

# set the flags for the compiler: all warnings
SET(CMAKE_CXX_FLAGS "-Wall")

set (PROGRAMS gcd_recursive gcd_nonrecursive fibonacci_recursive fibonacci_dynamic fibonacci_matrix merge_sort)
foreach(c ${PROGRAMS})
  add_executable(${c} ${c}.cpp)
endforeach(c)
