/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 11.1
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <string>
#include <stdexcept>


// abstract base class version using inheritance and runtime polymorphism
struct Function {
    typedef double result_type;
    typedef double argument_type;
    virtual result_type operator()(argument_type x) const=0;
    virtual ~Function() {}
};

// Simpson integration routine
Function::result_type integrate(const Function::argument_type a, const Function::argument_type b, const unsigned bins, const Function& f) {
    if (bins==0)
        throw std::logic_error("integrate(..) : number of bins has to be positive.");
    
    typedef Function::argument_type arg_type;
    typedef Function::result_type res_type;
    
    arg_type half_bin_size=(b-a)/static_cast<arg_type>(2*bins), x_;
    res_type sum_odd=f(a+half_bin_size), sum_even(0);
    
    for (unsigned i=1; i<bins; ++i) {
        x_=a+2*i*half_bin_size;
        sum_even+=f(x_);
        sum_odd+=f(x_+half_bin_size);
    }
    
    return (2.*sum_even + 4.*sum_odd + f(a) + f(b)) * half_bin_size / 3.;
}


struct sin_lambda : public Function
{
    sin_lambda( argument_type lambda = 1. ): lambda_(lambda){}
    result_type operator()( argument_type x ) const { return std::sin(lambda_*x); }

private:
    argument_type lambda_;
};

struct cos_lambda : public Function
{
    cos_lambda( argument_type lambda = 1. ): lambda_(lambda){}
    result_type operator()( argument_type x ) const { return std::cos(lambda_*x);  }

private:
    argument_type lambda_;
};

struct exp_lambda : public Function
{
    exp_lambda( argument_type lambda = 1. ): lambda_(lambda){}
    result_type operator()( argument_type x ) const { return std::exp(lambda_*x); }

private:
    argument_type lambda_;
};


Function* integrandFactory(std::string algorithm , Function::argument_type lambda )
{
    if (algorithm=="sin_lambda") {
        return new sin_lambda( lambda );
    } else if (algorithm=="cos_lambda") {
        return new cos_lambda( lambda );
    } else if (algorithm=="exp_lambda") {
        return new exp_lambda( lambda );
    } else {
        throw std::range_error("Choose an integrand: 'sin_lambda', 'cos_lambda', 'exp_lambda'.");
    }
}


int main(int argc, char ** argv)
{
    if (argc != 5 && argc != 6 ) {
        std::cerr << argv[0] << " <a> <b> <bins> <function_name> <lambda (optional)> " << std::endl;
        exit(1);
    }
    
    double a = std::stod( argv[1] );
    double b = std::stod( argv[2] );
    unsigned bins = std::stoi( argv[3] );
    
    double lambda = 1.;
    if (argc == 6)
        lambda = std::stod( argv[5] );
    
    Function* myintegrand = integrandFactory( std::string( argv[4] ) , lambda );
    
    std::cout.precision(15);
    std::cout << "Integral is: " << integrate( a , b , bins , *myintegrand ) << std::endl;
    
    delete myintegrand;
    return 0;
}
