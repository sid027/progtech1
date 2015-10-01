/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 2.2
 */

#include <cstdlib>
#include <cassert>

#include "simpson.hpp"

double integrate(const double a, const double b, const unsigned bins, double (*function) (double)) 
{
  assert(bins > 0);
  assert(function != NULL);

  const unsigned int steps = 2*bins + 1;

  const double dr = (b - a) / (steps - 1);

  double I = function(a);
  
  for(unsigned int i = 1; i < steps-1; ++i)
    I += 2 * (1.0 + i%2) * function(a + dr * i);

  I += function(b);
  
  return I * (1./3) * dr;
}

double my_sin(double value)
{
	return sin(value);
}

double my_fun(double value)
{
	return (1 + value);
}
