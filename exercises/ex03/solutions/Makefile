#Makefile

CXX = c++
CXXFLAGS = -O3 -std=c++11 -march=native -DNDEBUG

all: out.dat plot.py
	python plot.py out.dat

out.dat: cache
	./cache | tee out.dat

cache: cache.cpp
	$(CXX) $(CXXFLAGS) cache.cpp -o cache

