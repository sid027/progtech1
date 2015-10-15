add_library(random STATIC random.cpp)

install(TARGETS random DESTINATION lib)
install(FILES random.hpp DESTINATION include)
