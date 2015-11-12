#include "simpson.hpp"
#include <cassert>

double simpson(double (*f)(double), double a, double b, unsigned int N)
{
//    assert(a<b);
//    assert(N>0);

    if (b<a)
	  throw std::range_error("lower bound is not smaller than upper bound");
	  
	if (N==0)
	  throw std::range_error("zero steps not allowed");

	double       result=0;
	double       h=(b-a)/N;

	// boundary values
	result += ( f(a) + 4*f(a+h/2) + f(b) ) / 2.0;

	// values between boundaries
	for ( int i = 1; i <= N-1; ++i ) {
		result += f(a+i*h) + 2*f(a+(i+0.5)*h);
	}

	result *= h/3.0;

	return result;
}
