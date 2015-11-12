/* Programming Techniques for Scientific Simulations, HS 2015
 * Exercise 6.2
 */

#define _USE_MATH_DEFINES

#include <cmath>
#include <complex>
#include <iostream>

#include "simpson.hpp"

// function object with defined result_type and argument_type
template <class T, class V>
struct exp_minus_lambda_x {
    typedef T result_type;
    typedef V argument_type;
    
    exp_minus_lambda_x(const result_type lambda_value=1.0) : lambda(lambda_value) {}
    result_type operator()(const argument_type x) const { return std::exp(-lambda*x); }

    const result_type lambda;
};


// function object without definitions of result_type and argument_type
struct sin_lambda_x {
    sin_lambda_x(const double lambda_value=1.0) : lambda(lambda_value) {}
    double operator()(const double x) const { return std::sin(lambda*x); }

    const double lambda;
};

// we need to provide specialization on the traits for the sin_lambda_x
// as it does not have defined the argument_type and result_type
template<> struct domain_type<sin_lambda_x> { typedef double type; };
template<> struct result_type<sin_lambda_x> { typedef double type; };


std::complex<double> complex_exp(std::complex<double> x) { return std::exp(x); }


int main() {

    const unsigned int bins = 16;

    std::cout.precision(12);
    // function pointer with real domain and range
    std::cout << "int_0^1 e^x dx = " << integrate(0.,1.,bins,static_cast<double (*) (double)>(std::exp)) << std::endl;
    std::cout << " (precise value: " << std::exp(1)-1 << " )" << std::endl;
    
    // function pointer with complex domain and range
    std::cout << "int_0^1 e^x dx = " << integrate(std::complex<double>(0),std::complex<double>(0,M_PI),bins,complex_exp) << std::endl;
    std::cout << " (precise value: -2.0 )" << std::endl;
    
    // function object with real domain and range, both defined in the class
    exp_minus_lambda_x<double,double> exp_real_x(2.2);
    std::cout << "int_0^1 e^{-2.2*x} dx = " << integrate(0.,1.,bins,exp_real_x) << std::endl;
    std::cout << "       ( precise value: " << (1.-exp_real_x(1))/exp_real_x.lambda << " )" << std::endl;
    
    // function object with real domain and complex range, both defined in the class
    exp_minus_lambda_x<std::complex<double>,double> exp_i_x(std::complex<double>(0,-1));
    std::cout << "int_0^pi e^{i*x} dx = " << integrate(0.,M_PI,bins,exp_i_x) << std::endl;
    std::cout << "      (precise value: 2.0i )" << std::endl;
    
    // function object with complex domain and complex range, both defined in the class
    exp_minus_lambda_x<std::complex<double>,std::complex<double> > exp_i_x_(std::complex<double>(0,-1));
    std::cout << "int_0^pi e^{i*(x-1i)} dx = " << integrate(std::complex<double>(0,-1),std::complex<double>(M_PI,-1),bins,exp_i_x_) << std::endl;
    std::cout << "           (precise value: " << 2.*std::exp(1) << "i )" << std::endl;
    
    // function object with real domain and range, which is not defined in the class
    sin_lambda_x sin_kx(2);
    std::cout << "int_0^{pi/2} sin(2*x) dx = " << integrate(0.,M_PI/sin_kx.lambda,bins,sin_kx) << std::endl;
    std::cout << "           (precise value: " << 2.0/sin_kx.lambda << " )" << std::endl;

    return 0;
}
