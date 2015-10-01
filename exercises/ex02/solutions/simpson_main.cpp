/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 2.2
 */

#include <cmath>
#include <iostream>

#include "simpson.hpp"

int main() {

  const unsigned int bins = 5;

  std::cout.precision(15);
  std::cout << "I = " << integrate(0,M_PI,bins, my_fun ) << std::endl;
    
  return 0;
}
