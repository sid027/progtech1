# by Jakub Imriska, ITP, ETH Zurich, 2014
# for the lecture Programming Techniques for Scientific Simulations I (HS 14)
# for c++ basics catch-up exercise

COMPILER = g++
FLAGS = -Wall

all: gcd_recursive gcd_nonrecursive fibonacci_recursive fibonacci_dynamic fibonacci_matrix merge_sort

gcd_recursive: gcd_recursive.cpp
	$(COMPILER) $(FLAGS) gcd_recursive.cpp -o gcd_recursive

gcd_nonrecursive: gcd_nonrecursive.cpp
	$(COMPILER) $(FLAGS) $< -o $@

fibonacci_%: fibonacci_%.cpp
	$(COMPILER) $(FLAGS) $< -o $@

merge_sort: merge_sort.cpp
	$(COMPILER) $(FLAGS) $< -o $@

clean:
	rm -f gcd_recursive gcd_nonrecursive fibonacci_recursive fibonacci_dynamic fibonacci_matrix merge_sort
