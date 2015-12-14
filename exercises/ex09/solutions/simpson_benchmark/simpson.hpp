/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 9.2
 */

#ifndef SIMPSON_INTEGRATION_
#define SIMPSON_INTEGRATION_

#include <stdexcept>

// abstract base class version using inheritance and runtime polymorphism

struct Function {
    typedef double result_type;
    typedef double argument_type;
    virtual result_type operator()(const argument_type x) const=0;
    virtual ~Function() {}
};

Function::result_type Simpson_integrate(const Function& f, const Function::argument_type a, const Function::argument_type b, const unsigned N);



// template function object version using polymorphism at compile time

template <class F>
double Simpson_integrate(const F& f, const double a, const double b, const unsigned N) {
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



// function pointer version

double Simpson_integrate(double (*f)(double), const double a, const double b, const unsigned N);



// hard-coded version

double Simpson_integrate(const double a, const double b, const unsigned N);



#endif  //SIMPSON_INTEGRATION_
