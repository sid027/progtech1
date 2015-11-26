# Programming Techniques for Scientific Simulations, HS 2014

CXX = c++
CXXFLAGS = -Wall -O3 -DNDEBUG -std=c++11

ifeq ($(shell uname),Darwin) # detect if Os is OsX
  LDFLAGS = -framework Accelerate
else
  LDFLAGS = -lblas -lgfortran
endif

all: matrixmult strassen

matrixmult: matrixmult.cpp
	$(CXX) $(CXXFLAGS) matrixmult.cpp -o matrixmult $(LDFLAGS)

strassen: strassen.cpp
	$(CXX) $(CXXFLAGS) strassen.cpp -o strassen

clean:
	rm matrixmult strassen
