/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 9.1
 */

#include <stdexcept>

#include "simpson.hpp"

// abstract base class version using inheritance and runtime polymorphism

Function::result_type integrate(const Function::argument_type a, const Function::argument_type b, const unsigned bins, const Function& f) {
    if (bins==0)
        throw std::logic_error("integrate(..) : number of bins have to be positive.");
    
    Function::argument_type half_bin_size=(b-a)/static_cast<Function::argument_type>(2*bins), x_;
    Function::result_type sum_odd=f(a+half_bin_size), sum_even(0);
    
    for (unsigned i=1; i<bins; ++i) {
        x_=a+2*i*half_bin_size;
        sum_even+=f(x_);
        sum_odd+=f(x_+half_bin_size);
    }
    
    return (2.*sum_even + 4.*sum_odd + f(a) + f(b)) * half_bin_size / 3.;
}
