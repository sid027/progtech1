/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 2.1b
 */

#include <iostream>
#include <algorithm>

int main() 
{
  int capacity(1);
  double* array = new double[capacity];

  int n(0); double sum(0);
  while(std::cin >> array[n]){
    sum+=array[n++];
    if(n==capacity){
      capacity*=2;
      double* new_array = new double[capacity];
      std::copy(array, array + n, new_array);
      delete[] array;
      array = new_array;
    }

  }

  for(int i=n-1; i>=0; --i)
    std::cout << array[i]/sum << std::endl;
    
  return 0;
}
