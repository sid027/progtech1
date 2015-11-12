CXX = c++
CXXFLAGS = -Wall -O3 -std=c++11 -DNDEBUG

all: penna_sim population.pdf

clean:
	rm *.o penna_sim

penna_sim: main.o population.o fish.o genome.o
	$(CXX) $(CXXFLAGS) -o $@  main.o population.o fish.o genome.o

%.o: %.cpp *.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

population.dat gene_histogram.dat: penna_sim run.sh
	./run.sh

population.pdf gene_histogram.pdf: plot.py population.dat gene_histogram.dat
	python plot.py
