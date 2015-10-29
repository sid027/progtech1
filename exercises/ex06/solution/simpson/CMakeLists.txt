cmake_minimum_required(VERSION 2.8)

project(SimpsonIntegrationFunctionObjectApproch)

add_executable(simpson main.cpp)

install(TARGETS simpson DESTINATION bin)
