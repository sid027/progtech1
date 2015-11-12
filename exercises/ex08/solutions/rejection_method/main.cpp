/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 10.2
 */

#include <iostream>
#include <cmath>
#include <string>

#include "modified_normal_distribution.hpp"

int main(int argc, char** argv) {
  std::size_t sample_size=1000000;
  if (argc>1) sample_size=std::stoull(argv[1]);  // sample size taken as the optional 1st argument

  double p=1.0;
  if (argc>2) p=std::stod(argv[2]);  // parameter of the distribution taken as the optional 2nd argument
  modified_normal_distribution<> mcd(p);

  std::mt19937 rnd;
  if (argc==4) rnd.seed(std::stoull(argv[3]));  // seed taken as the optional 3rd argument

  double sum(0), sum_sq(0), x;
  for(std::size_t i=0; i<sample_size; ++i) {
    x = mcd(rnd);
    sum += x;
    sum_sq += x*x;
  }

  double mean = sum/sample_size;
  double stddev = std::sqrt((sum_sq-mean*sum)/(sample_size-1.));
  double stddev_exact = std::sqrt((std::exp(2)-3.)/(std::exp(2)+1))*p;
  std::cout << "Mean: " << mean << " +- " << stddev/std::sqrt(sample_size) << "   (exact: 0.0)" << std::endl;
  std::cout << "StdDev: " << stddev << " +- " << stddev/std::sqrt(2.*(sample_size-1)) << "   (exact: " << stddev_exact << ")" << std::endl;
  std::cout << "Acceptance rate: "  << mcd.acceptance_ratio() << " +- " << std::sqrt(mcd.acceptance_ratio()*(1.-mcd.acceptance_ratio())/(sample_size-1.))
            << "   (exact:" << 0.5*(1.+std::exp(-2.)) << ")" << std::endl;

  return 0;
}
