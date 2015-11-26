# Programming Techniques for Scientific Simulations I (HS 14)
# Week 11

cmake_minimum_required(VERSION 2.8)

# you may manually set the compiler if you want
#SET(CMAKE_CXX_COMPILER "c++")

# set the flags for the compiler: all warnings
SET(CMAKE_CXX_FLAGS "-Wall -std=c++11")
SET(CMAKE_BUILD_TYPE RELEASE)

if(APPLE)
  find_library(ACCELERATE_LIBRARY Accelerate )
  mark_as_advanced(ACCELERATE_LIBRARY)
  set(EXTRA_LIBS ${ACCELERATE_LIBRARY})
else()
  set(EXTRA_LIBS blas gfortran)	
endif()

set (PROGRAMS strassen matrixmult)
foreach(c ${PROGRAMS})
  add_executable(${c} ${c}.cpp)
endforeach(c)

target_link_libraries(matrixmult ${EXTRA_LIBS})

install(TARGETS ${PROGRAMS} DESTINATION bin)
