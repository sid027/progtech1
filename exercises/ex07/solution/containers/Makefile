#Makefile

CXX = c++
CXXFLAGS = -O3 -std=c++0x -march=native -DNDEBUG

all: containers.png

containers: containers.cpp
	$(CXX) $(CXXFLAGS) containers.cpp -o containers	

containers.dat: containers
	./containers | tee containers.dat

containers.png: containers.dat containers_plot.p
	gnuplot containers_plot.p

clean:
	rm -f  containers
