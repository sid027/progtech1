/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 9.1
 */

#define _USE_MATH_DEFINES

#include <cmath>
#include <iostream>

#include "simpson.hpp"


struct sin_lambda_x : public Function {
    sin_lambda_x(const Function::argument_type lambda_=1.) : lambda(lambda_) {}
    Function::result_type operator()(const Function::argument_type x) const { return std::sin(lambda*x); }
    const Function::argument_type lambda;
};


int main() {
  
  const unsigned int bins = 8;
  const sin_lambda_x::argument_type lambda = 2.;
  
  std::cout.precision(15);
  std::cout << "I = " << integrate(0,M_PI/lambda,bins,sin_lambda_x(lambda)) << "   (precise value: " << 2./lambda << ")" << std::endl;
  
  return 0;
}
