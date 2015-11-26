/* Programming Techniques for Scientific Simulations, HS 2015
 * Exercise 11.0
 */

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

#include "simpson.hpp"

real_type exp_minus_x(real_type x) {return std::exp(-x);}
real_type non_smooth(real_type x) {return std::abs(x-1.0/M_PI);}
real_type discontinous(real_type x) {return x < 1.0/M_PI ? x*x : (x-1.0/M_PI);}



int main() {

  unsigned int bins;
  const real_type exact_exp = 1.0 - std::exp(-1.0);
  const real_type exact_discontinous = 1.0/M_PI/M_PI/M_PI/3.0+(1.0-1.0/M_PI)*(1.0-1.0/M_PI)/2.0;
  const real_type exact_non_smooth = 1.0/M_PI/M_PI-1.0/M_PI+0.5;
  
  std::cout.precision(15);
  for(std::size_t i=0; i<26; ++i) {
    bins= 1 << i;
    std::cout << bins << "\t" << std::abs(integrate(0.0,1.0,bins,exp_minus_x) - exact_exp) << "\t" 
	      << std::abs(integrate(0.0,1.0,bins,non_smooth) - exact_non_smooth) << "\t" 
	      << std::abs(integrate(0.0,1.0,bins,discontinous) - exact_discontinous) << "\t"  << std::endl;    
	      
  }

  return 0;
}
