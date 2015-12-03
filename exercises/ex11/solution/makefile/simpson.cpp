/* Programming Techniques for Scientific Simulations, HS 2015
 * Exercise 11.0
 */

#include <cstdlib>
#include <cassert>

#include "simpson.hpp"

real_type integrate(const real_type a, const real_type b, const unsigned bins, real_type(*function) (real_type)) 
{
  assert(bins > 0);
  assert(function != NULL);

  const unsigned int steps = 2*bins + 1;

  const real_type dr = (b - a) / (steps - 1);

  real_type I = function(a);
  
  for(unsigned int i = 1; i < steps-1; ++i)
    I += 2 * (1.0 + i%2) * function(a + dr * i);

  I += function(b);
  
  return I * (1./3) * dr;
}
