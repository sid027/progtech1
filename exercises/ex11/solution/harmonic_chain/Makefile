# Programming Techniques for Scientific Simulations, HS 2015

CXX = c++
CXXFLAGS = -Wall -O3 -DNDEBUG -std=c++0x

ifeq ($(shell uname),Darwin) # detect if Os is OsX
  LDFLAGS = -framework Accelerate
else
  LDFLAGS = -llapack -lblas -lgfortran
endif

all: harmonic_chain

% : %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

clean:
	rm harmonic_chain
