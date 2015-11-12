#include <iostream>
#include <stdexcept>

namespace Stack {
  
  struct stack 
  {
    double* s; // pointer to allocated memory 
    double* p; // stack pointer
    int n;     // stack size
  };

  void init(stack& s, int l) 
  {
    s.s=new double[l];
    s.p=s.s;
    s.n=l;
  }

  void destroy(stack& s) 
  {
    delete[] s.s;
  }

  void push(stack& s, double v) 
  {
    if(s.p==s.s+s.n-1) 
	  throw std::runtime_error("stack overflow");
    *s.p++=v;
  }

  double pop(stack& s) 
  {
    if(s.p==s.s) 
	  throw std::runtime_error("stack underflow");
    return *--s.p;}
  }

int main() {
  try {
    Stack::stack s;
    Stack::init(s,100); // must be called
    Stack::push(s,10.);
    std::cout << Stack::pop(s) << std::endl;
    std::cout << Stack::pop(s) << std::endl; // throws error
    Stack::destroy(s); // must be called
  }
  catch (std::exception& e) {
    std::cerr << "Exception occured: " << e.what() << std::endl;
	return -1;
  }
  return 0;
}

