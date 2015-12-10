/* Programming Techniques for Scientific Simulations, HS 2014
 * Week 13
 */
 
#include <iostream>
#include "algorithmic_derivation.hpp"


int main() {
  Variable<int> x;
  auto expr = (constant(5)*x*(x+constant(1))+constant(72)*x+constant(38));  // uses c++11
    // expression: 5*x*(x+1)+72*x+38 = 5*x^2 + 77*x + 38
    // derivative: 10*x+77
  std::cout << expr(8) << ' ' << expr.derivative(8) << std::endl;
  
  return 0;
}
