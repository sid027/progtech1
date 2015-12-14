/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 9.2
 */

#include "simpson.hpp"
#include "test_functions_macros.hpp"



// abstract base class version using inheritance and runtime polymorphism

Function::result_type Simpson_integrate(const Function& f, const Function::argument_type a, const Function::argument_type b, const unsigned N) {
    if (N==0)
        throw std::logic_error("Simpson_integrate(..) : number of bins have to be positive.");
    typedef Function::argument_type argument_type;
    typedef Function::result_type result_type;
    typedef unsigned int_t;
    
    argument_type half_bin_size = (b-a)/static_cast<argument_type>(2*N);
    argument_type x_=a+half_bin_size;
    result_type sum_odd=f(x_);
    result_type sum_even(0);
    
    for (int_t i=1; i<N; ++i) {
        x_=a+2*i*half_bin_size;
        sum_even+=f(x_);
        sum_odd+=f(x_+half_bin_size);
    }
    
    return (2.*sum_even + 4.*sum_odd + f(a) + f(b)) * half_bin_size / 3.;
}



// function pointer version

double Simpson_integrate(double (*f)(double), const double a, const double b, const unsigned N) {
    if (N==0)
        throw std::logic_error("Simpson_integrate(..) : number of bins have to be positive.");
    typedef double argument_type;
    typedef double result_type;
    typedef unsigned int_t;
    
    argument_type half_bin_size = (b-a)/static_cast<argument_type>(2*N);
    argument_type x_=a+half_bin_size;
    result_type sum_odd=f(x_);
    result_type sum_even(0);
    
    for (int_t i=1; i<N; ++i) {
        x_=a+2*i*half_bin_size;
        sum_even+=f(x_);
        sum_odd+=f(x_+half_bin_size);
    }
    
    return (2.*sum_even + 4.*sum_odd + f(a) + f(b)) * half_bin_size / 3.;
}



// hard-coded version

double Simpson_integrate(const double a, const double b, const unsigned N) {
    if (N==0)
        throw std::logic_error("Simpson_integrate(..) : number of bins have to be positive.");
    typedef double argument_type;
    typedef double result_type;
    typedef unsigned int_t;
    
    argument_type half_bin_size = (b-a)/static_cast<argument_type>(2*N);
    argument_type x_=a+half_bin_size;
    result_type sum_odd=FUNCTION_TO_INTEGRATE(x_);
    result_type sum_even(0);
    
    for (int_t i=1; i<N; ++i) {
        x_=a+2*i*half_bin_size;
        sum_even+=FUNCTION_TO_INTEGRATE(x_);
        sum_odd+=FUNCTION_TO_INTEGRATE(x_+half_bin_size);
    }
    
    return (2.*sum_even + 4.*sum_odd + FUNCTION_TO_INTEGRATE(a) + FUNCTION_TO_INTEGRATE(b)) * half_bin_size / 3.;
}
