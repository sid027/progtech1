#include <iostream>
#include <stdexcept>

namespace Stack {
  
  template <class T>
  class stack 
  {
    T* s; // pointer to allocated memory 
    T* p; // stack pointer
    int n;     // stack size
  public:
    stack(int l) : s(new T[l]), p(s), n(l) {} 
    ~stack() { delete[] s;}

    void push(T v) 
    {
      if(p==s+n-1) 
	throw std::runtime_error("stack overflow");
      *p++=v;
    }

    T pop() 
    {
      if(p==s) 
	throw std::runtime_error("stack underflow");
      return *--p;
    }
  };
}

int main() {
  try {
    Stack::stack<double> s(100);
    s.push(10.3);
    std::cout << s.pop() << std::endl;

    Stack::stack<int> si(100);
    si.push(10);
    std::cout << si.pop() << std::endl;
  }
  catch (std::exception& e) {
    std::cerr << "Exception occured: " << e.what() << std::endl;
    return -1;
  }
  return 0;
}

