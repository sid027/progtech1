cmake_minimum_required( VERSION 2.8 )

project(PennaGenomeFishTesting)

set(CMAKE_CXX_FLAGS "-std=c++0x")

add_library(Penna STATIC genome.cpp fish.cpp)

add_executable(genome-test genome-test.cpp)
add_executable(fish-test fish-test.cpp)

target_link_libraries(genome-test Penna)
target_link_libraries(fish-test Penna)

install(TARGETS genome-test fish-test DESTINATION bin)

install(TARGETS Penna
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

install(FILES genome.hpp fish.hpp DESTINATION include)


