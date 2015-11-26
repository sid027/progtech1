cmake_minimum_required( VERSION 2.8 )

project(PennaPopulation)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

add_library(Penna STATIC genome.cpp fish.cpp population.cpp)

add_executable(penna_sim main.cpp)

target_link_libraries(penna_sim Penna)

install(TARGETS Penna
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

install(TARGETS penna_sim DESTINATION bin)
install(FILES run.sh plot.py DESTINATION bin)

install(FILES genome.hpp fish.hpp population.hpp DESTINATION include)


