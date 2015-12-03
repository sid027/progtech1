# Programming Techniques for Scientific Simulations, HS 2015
# Exercise 11.0

COMPILER = g++
FLAGS = -Wall -O3 -DNDEBUG

all: convergence.png convergence.pdf

convergence.pdf: plot.py convergence.dat
	python $<

convergence.png: plot.gp convergence.dat
	gnuplot $<

convergence.dat: simpson
	./$< | tee $@

simpson: libintegrate.a main.o
	$(COMPILER) $(FLAGS) main.o -o $@ -L. -lintegrate

libintegrate.a: simpson.o
	ar ruc $@ $<
	ranlib $@

%.o: %.cpp simpson.hpp
	$(COMPILER) $(FLAGS) -c $<

clean:
	rm -f *.o *.a simpson convergence.dat convergence.png convergence.pdf
