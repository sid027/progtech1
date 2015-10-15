add_library(timer STATIC timer.cpp)

install(TARGETS timer DESTINATION lib)
install(FILES timer.hpp DESTINATION include)
