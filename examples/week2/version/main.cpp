#include <iostream>
#include "square.hpp"

int main()
{
  std::cout << "Using version " << square::version() << " of the square library.\n";
  std::cout << "The square of 5 is " << square::square(5.) << std::endl;
}
