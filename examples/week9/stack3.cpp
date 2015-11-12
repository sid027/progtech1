#include <iostream>
#include <stdexcept>

namespace Stack {
  
  class stack 
  {
    double* s; // pointer to allocated memory 
    double* p; // stack pointer
    int n;     // stack size
  public:
    stack(int l) : s(new double[l]), p(s), n(l) {} 
    ~stack() { delete[] s;}

    void push(double v) 
    {
      if(p==s+n-1) 
	    throw std::runtime_error("stack overflow");
      *p++=v;
    }

    double pop() 
    {
      if(p==s) 
	    throw std::runtime_error("stack underflow");
      return *--p;
    }
  };
}

int main() {
  try {
    Stack::stack s(100);
    s.push(10.);
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl; // throws error
  }
  catch (std::exception& e) {
    std::cerr << "Exception occured: " << e.what() << std::endl;
	return -1;
  }
  return 0;
}

