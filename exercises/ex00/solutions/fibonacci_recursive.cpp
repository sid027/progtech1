/* Example code written by Jakub Imriska, ITP, ETH Zurich, 2014
 * for the lecture Programming Techniques for Scientific Simulations I (HS 14)
 * for c++ basics catch-up exercise
 */

/// NOTE: for n>93, the program does not work correctly due to integer overflow

#include<iostream>

unsigned long long Fibonacci(unsigned n) {
  if (n==0) return 0;
  if (n==1) return 1;
  return Fibonacci(n-1)+Fibonacci(n-2);
}

int main() {
  unsigned n;
  /// read input
  std::cout<<"The program will compute the Fibonacci(n). Set n: ";
  std::cin>>n;
  
  /// compute Fibonacci(n)
  std::cout<<"Fibonacci("<<n<<") = "<<Fibonacci(n)<<std::endl;
  
  return 0;
}
