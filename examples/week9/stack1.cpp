#include <iostream>

void push(double*& s, double v) 
{
  *s++=v;
}

double pop(double*& s) 
{
  return *--s;
}

int main() 
{

  double stack[1000];
  
  double* p=stack;

  push(p,10.);

  std::cout << pop(p) << std::endl;
  std::cout << pop(p) << std::endl; 
  // error of popping below
  // beginning goes undetected!
}
