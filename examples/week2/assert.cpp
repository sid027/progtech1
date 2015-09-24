#include <iostream>
#include <cmath>
#include <cassert>

double checked_sqrt(double x)
{
  assert(x>=0.);
  return sqrt(x);
}


int main()
{
  double x;
  std::cin >> x;
  std::cout << checked_sqrt(x) << "\n";
}
