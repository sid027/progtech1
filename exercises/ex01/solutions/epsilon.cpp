/* Programming Techniques for Scientific Simulations, HS 2015
 * Exercise 1.5
 */

#include <iostream>
#include <limits>

double macheps() {

  const double beta(1.0); 
  double alpha(1.0);

  while(double(alpha+beta)>beta)
    alpha /= 2;

  return alpha*2;
}

int main() 
{

  std::cout 
    << "macheps for double = "<< macheps() << ' '
    << '(' << std::numeric_limits<double>::epsilon() << " theoretical)"
    << std::endl;
        
  return 0;
}
