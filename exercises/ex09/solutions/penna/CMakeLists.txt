cmake_minimum_required( VERSION 2.8 )

project(PennaPopulation)

set(CMAKE_CXX_FLAGS "-Wall -std=c++0x")

add_library(Penna STATIC fishing_population.cpp population.cpp genome.cpp fish.cpp)

add_executable(penna_sim main.cpp)

target_link_libraries(penna_sim Penna)

install(TARGETS Penna
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib)

install(TARGETS penna_sim DESTINATION bin)
install(FILES run.sh plot.py DESTINATION bin)

install(FILES genome.hpp animal.hpp population.hpp DESTINATION include)


