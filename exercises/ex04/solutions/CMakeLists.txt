cmake_minimum_required( VERSION 2.8 )

project(pt15_week4)

SET(CMAKE_CXX_FLAGS "-std=c++11")
set(CMAKE_INSTALL_PREFIX ${CMAKE_HOME_DIRECTORY}/install )
set(DIRECTORIES timer random benchmark)

foreach(directory ${DIRECTORIES})
	add_subdirectory(${directory})
endforeach(directory)
