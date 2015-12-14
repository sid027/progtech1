#!/bin/bash

# Programming Techniques for Scientific Simulations, HS 2014
# Exercise 9.2


# run all executables, each one for a function to be tested
./simpson_benchmark_1 | tee simpson_benchmark_results.dat
./simpson_benchmark_2 | tee -a simpson_benchmark_results.dat
./simpson_benchmark_3 | tee -a simpson_benchmark_results.dat
./simpson_benchmark_4 | tee -a simpson_benchmark_results.dat
./simpson_benchmark_5 | tee -a simpson_benchmark_results.dat
./simpson_benchmark_6 | tee -a simpson_benchmark_results.dat

# show a plot
python plot.py
