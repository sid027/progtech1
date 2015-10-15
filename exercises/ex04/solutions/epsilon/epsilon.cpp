/* Programming Techniques for Scientific Simulations, HS 2015
 * Exercise 4.1
 */

#include <iostream>
#include <limits>

template <class T>
T get_epsilon() {
    T tmp, beta(1.0), alpha(1.0);
    do {
      alpha /= 2;
      tmp = alpha+beta;
    } while (tmp>beta);
    return alpha*2;
}

int main() {
    std::cout<<"Epsilon for float = "<<get_epsilon<float>()<<"  compare with  "<<std::numeric_limits<float>::epsilon()<<std::endl;
    std::cout<<"Epsilon for double = "<<get_epsilon<double>()<<"  compare with  " <<std::numeric_limits<double>::epsilon()<<std::endl;
    std::cout<<"Epsilon for long double = "<<get_epsilon<long double>()<<"  compare with  "<<std::numeric_limits<long double>::epsilon()<<std::endl;
        
    return 0;
}
