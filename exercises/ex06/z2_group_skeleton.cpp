#include <iostream>

enum Z2 { Plus, Minus };

template<class T>
T identity_element() { return T(1); }

// to be implemented: specialize the previous function for Z2


Z2 operator*(const Z2 a, const Z2 b)
{
  // to be implemented
}

std::ostream& operator<<(std::ostream& os, const Z2 a)
{
  // to be implemented
}

template<class T>
T operator*(const T a, const Z2 b)
{
  // to be implemented
}

template<class T>
T operator*(const Z2 b, const T a)
{
  // to be implemented
}

template<class T>
T mypow(T a, const unsigned int n)
{
  // to be implemented
}

int main()
{
  // some testing: feel free to add your own!
  std::cout << Plus*Minus << std::endl;
  std::cout << Plus*-1*Minus << std::endl;
  std::cout << (1.+3.)*mypow(Minus,4) << std::endl;
  for (unsigned i=0; i<7; i++)
    std::cout << "Plus^" << i << " = " << mypow(Plus,i) << std::endl;
  for (unsigned i=0; i<7; i++)
    std::cout << "Minus^" << i << " = " << mypow(Minus,i) << std::endl;
  for (unsigned i=0; i<7; i++)
    std::cout << "2^" << i << " = " << mypow(2.0,i) << std::endl;
  return 0;
}
