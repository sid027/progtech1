/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 9.1
 */

#ifndef SIMPSON_HPP
#define SIMPSON_HPP


// abstract base class version using inheritance and runtime polymorphism

struct Function {
    typedef double result_type;
    typedef double argument_type;
    virtual result_type operator()(argument_type x) const=0;
    virtual ~Function() {}
};


Function::result_type integrate(const Function::argument_type a, const Function::argument_type b, const unsigned bins, const Function& f);

/* PRECONDITIONS: 

   the domain of the function f(x) has cover the interval
   [min(a,b),max(a,b)]

   boundary values 'a' and 'b' are convertible to double 

   'bins' convertible to unsigned
   
   'bins' > 0 
 
  POSTCONDITIONS: the return value will approximate the integral of
       the function f(x) over the interval [min(a,b),max(a,b)]
       by the use of the Simpson rule with 'bins' equally sized
       intervals
 
  COMPLEXITY: number of function calls = 2*bins+1
  
  DOCUMENTATION: the interval given by the boundaries 'a' and 'b' will
       be divided to 'bins' equally sized bins, the function f
       will be aproximated by a parabola using the function
       values at the bin-boundaries and in the bin-midpoint the
       integral will be approximated by the sum of the integrals over
       each bin of the corresponding interpolating parabola
 */

#endif
