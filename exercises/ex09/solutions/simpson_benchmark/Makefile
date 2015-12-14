# Programming Techniques for Scientific Simulations, HS 2014
# Exercise 9.2

COMPILER = c++
FLAGS = -O3 -funroll-loops -std=c++0x -DNDEBUG

BENCHMARKS = simpson_benchmark_1 simpson_benchmark_2 simpson_benchmark_3 simpson_benchmark_4 simpson_benchmark_5 simpson_benchmark_6

all: simpson_benchmark.pdf

simpson_benchmark.pdf: $(BENCHMARKS)
	./simpson_benchmark.sh	

simpson_benchmark_%: simpson_%.o simpson_benchmark.cpp simpson.hpp test_functions_macros.hpp
	$(COMPILER) $(FLAGS) -DF$* simpson_benchmark.cpp -o $@ $<

simpson_%.o: simpson.hpp simpson.cpp simpson.hpp test_functions_macros.hpp
	$(COMPILER) $(FLAGS) -c -DF$* simpson.cpp -o $@

clean:
	rm -f *.o $(BENCHMARKS)
