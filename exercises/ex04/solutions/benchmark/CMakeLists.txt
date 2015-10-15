include_directories(${CMAKE_HOME_DIRECTORY}/timer ${CMAKE_HOME_DIRECTORY}/random )
link_directories(${PROJECT_BINARY_DIR}/timer ${PROJECT_BINARY_DIR}/random )

add_executable(benchmark main.cpp)
target_link_libraries(benchmark random timer)

install(TARGETS benchmark DESTINATION bin)
