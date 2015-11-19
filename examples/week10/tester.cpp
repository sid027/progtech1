#include "penna_vector.hpp"

#include <iostream>
#include <cmath>
#include <functional>
#include <cstdlib>

class T {
public:
	void set(double t) {a=t;}
	void show() {std::cout << a << std::endl;}
	bool big_enough() {return (a>0.2);}
private:
  double a;
};

int main() {
	penna_vector<T> my(10);

	for (penna_vector<T>::iterator it=my.begin();it!=my.end();it++)
		it->set(drand48());

	my.remove_if(std::mem_fun_ref(&T::big_enough));
  std::for_each (my.begin(),my.end(),std::mem_fun_ref(&T::show));
	
return 0;
}
