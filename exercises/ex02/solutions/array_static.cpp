/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 2.1a
 */

#include <iostream>

#define max_items 10

int main() 
{
  double array[max_items];

  int n(0); double sum(0);
  while(n<max_items && std::cin >> array[n])
    sum+=array[n++];

  for(int i=n-1; i>=0; --i)
    std::cout << array[i]/sum << std::endl;

  return 0;
}
