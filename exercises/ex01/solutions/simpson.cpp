/* Programming Techniques for Scientific Simulations, HS 2015
 * Exercise 1.6
 */

#include <iostream>
#include <cmath>

inline double function(const double x) 
{
  return std::sin(x);
}

double integrate(const double a, const double b, const unsigned bins) 
{
  const double dr = (b - a) / (2*bins);

  double I = function(a);
  
  for(unsigned int i = 1; i < 2*bins; ++i)
    I += 2 * (1.0 + i%2) * function(a + dr * i);

  I += function(b);
  
  return I * (1./3) * dr;
}

int main() {

  const unsigned int bins = 5;

  std::cout.precision(15);
  std::cout 
    << "I = " << integrate(0,M_PI,bins) << "   (exact: 2.0)" 
    << std::endl;
    
  return 0;
}
