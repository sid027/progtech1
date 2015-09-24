/* Example code written by Jakub Imriska, ITP, ETH Zurich, 2014
 * for the lecture Programming Techniques for Scientific Simulations I (HS 14)
 * for c++ basics catch-up exercise
 */

#include<iostream>

unsigned int gcd(unsigned int a, unsigned int b) {
  while (a>0 && b>0) {
    if (a>b) a=a%b;
    else b%=a;
  }
  return a+b;
}

int main() {
  unsigned int a,b;
  
  /// read input
  std::cout<<"Set unsigned int a: ";
  std::cin>>a;
  std::cout<<"Set unsigned int b: ";
  std::cin>>b;
  
  /// compute gcd
  std::cout<<"gcd("<<a<<", "<<b<<") = "<<gcd(a,b)<<std::endl;
  
  return 0;
}
