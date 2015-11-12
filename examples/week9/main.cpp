#include <iostream>
#include <cmath>
#include "simpson.hpp"

double my(double x) {
  return 3.*sin(3.*x-1);
}

int main() {  
  bool done; 
  do {   
    done = true;   
    try {     
       double a,b;     
       unsigned int n;      
       std::cin >> a >> b >> n;     
       std::cout << simpson(sin,a,b,n);   
    }   
    catch (std::range_error& e) {     // also catches derived exceptions     
      std::cerr << "Range error: " << e.what() << "\n";     
      done=false;   
    }
  } while (!done);
}
