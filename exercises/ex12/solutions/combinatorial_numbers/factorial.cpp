#include <iostream>

typedef unsigned long long uint_t;

template<uint_t n, uint_t temp>
struct factorial{
  static uint_t eval() { return factorial<n-1,temp*n>::eval();}
};

template<uint_t temp>
struct factorial<0,temp> {
  static uint_t eval() { return temp;}
};

uint_t fac_test(uint_t n) {
  uint_t f=n>0?n:1;
  while(n>2){
    f*=(--n);
  }
  return f;
}

int main() {
  std::cout << factorial<0,1>::eval() << "\t" << fac_test(0) << std::endl;
  std::cout << factorial<1,1>::eval() << "\t" << fac_test(1) << std::endl;
  std::cout << factorial<2,1>::eval() << "\t" << fac_test(2) << std::endl;
  std::cout << factorial<3,1>::eval() << "\t" << fac_test(3) << std::endl;
  std::cout << factorial<4,1>::eval() << "\t" << fac_test(4) << std::endl;
  std::cout << factorial<5,1>::eval() << "\t" << fac_test(5) << std::endl;  
  std::cout << factorial<6,1>::eval() << "\t" << fac_test(6) << std::endl;
  std::cout << factorial<7,1>::eval() << "\t" << fac_test(7) << std::endl;
  std::cout << factorial<8,1>::eval() << "\t" << fac_test(8) << std::endl;
  std::cout << factorial<9,1>::eval() << "\t" << fac_test(9) << std::endl;  
  return 0;
}
