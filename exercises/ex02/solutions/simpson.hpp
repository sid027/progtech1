/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 2.2
 */

#ifndef SIMPSON_HPP
#define SIMPSON_HPP

double my_fun(double value);

double my_sin(double value); 

double integrate(const double a, const double b, const unsigned bins, double (*function)(double));

/* PRECONDITIONS: 

   the domain of the function function(x) has cover the interval
   [min(a,b),max(a,b)]

   boundary values 'a' and 'b' are convertible to double 

   'bins' convertible to unsigned
   
   'bins' > 0 
 
  POSTCONDITIONS: the return value will approximate the integral of
       the function function(x) over the interval [min(a,b),max(a,b)]
       by the use of the Simpson rule with 'bins' equally sized
       intervals
 
  COMPLEXITY: number of function calls = 2*bins+1
  
  DOCUMENTATION: the interval given by the boundaries 'a' and 'b' will
       be divided to 'bins' equally sized bins, the function
       'function' will be aproximated by a parabola using the function
       values at the bin-boundaries and in the bin-midpoint the
       integral will be approximated by the sum of the integrals over
       each bin of the corresponding interpolating parabola
 */

#endif
