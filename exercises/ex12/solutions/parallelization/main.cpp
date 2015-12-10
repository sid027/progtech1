/* Programming Techniques for Scientific Simulations, HS 2015
 * Exercise 12
 */

#include <cmath>
#include <iostream>
#include <omp.h>

#include "simpson.hpp"


struct exp_minus_lambda_x {
  typedef double argument_type;
  typedef double result_type;
  
  exp_minus_lambda_x(const result_type lambda_value=1.0) : lambda(lambda_value) {}
    
  inline result_type operator()(const argument_type x) const { return std::exp(-lambda*x); }
  
  const result_type lambda;
};


int main() {
  const unsigned bins=4194304;
  const double a(0);
  const double b(1);
  
  std::cout.precision(15);
  // call using function object
  exp_minus_lambda_x func(2.);
  double result=0;
#pragma omp parallel reduction(+:result)
  {
    int n=omp_get_num_threads();
    int i=omp_get_thread_num();
    double step=(b-a)/n;
    result+=integrate(a+i*step,a+(i+1)*step,bins/n,func);
  }
  
  std::cout << "int_a^b exp(-lambda*x) dx  = " << result << "  (function object version)" << std::endl;
  
  // analytic result for check
  std::cout << "            analytic result: " << (func(a)-func(b))/func.lambda << std::endl;
  
  return 0;
}
