#Makefile

CXX = g++
CXXFLAGS = -O3 -DNDEBUG -std=c++11

all: random.pdf

random.pdf: random.dat random_plot.py
	python random_plot.py

random.dat: random
	./$< | tee $@

random: main.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f random 
