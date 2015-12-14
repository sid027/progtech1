cmake_minimum_required( VERSION 2.8 )

project(SimpsonBenchmark)

set( CMAKE_CXX_FLAGS "-Wall -DNDEBUG -O3 -std=c++0x -funroll-loops" )
set( CMAKE_BUILD_TYPE RELEASE )

foreach(i 1 2 3 4 5 6)
  add_executable(simpson_benchmark_${i} simpson_benchmark.cpp simpson.cpp)
  set_target_properties(simpson_benchmark_${i} PROPERTIES COMPILE_FLAGS "-DF${i}")
  install(TARGETS simpson_benchmark_${i} DESTINATION bin)
endforeach()

install(FILES simpson_benchmark.sh plot.py DESTINATION bin)

