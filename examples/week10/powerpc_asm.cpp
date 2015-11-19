#include <iostream>
inline int count_leading_zeros (int x)
{
  int c;
  asm ("cntlzw %1,%0" : "=r" (c) : "r" (x) );
  return c;
}

int main() { 
  int i; 
  std::cout << "Enter a number\n";
  std::cin >> i; 
  std::cout << "has " << count_leading_zeros(i) << " leading zeroes\n";
  return 0;
}
