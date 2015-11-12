/* Programming Techniques for Scientific Simulations, HS 2015
 * Exercise 6.2
 */

#ifndef SIMPSON_HPP
#define SIMPSON_HPP

#include <cassert>

template <class F>
struct domain_type { typedef typename F::argument_type type; };

template <class R, class T>
struct domain_type<R(*)(T)> { typedef T type; };

template <class R, class T>
struct domain_type<R(T)> { typedef typename domain_type<R(*)(T)>::type type; };

template <class F>
struct result_type { typedef typename F::result_type type; };

template <class R, class T>
struct result_type<R(*)(T)> { typedef R type; };

template <class R, class T>
struct result_type<R(T)> { typedef typename result_type<R(*)(T)>::type type; };


template <class F>
typename result_type<F>::type integrate(typename domain_type<F>::type a, typename domain_type<F>::type b, unsigned int bins, const F& func)
{
    assert(bins > 0);
    
    typedef typename domain_type<F>::type domain_t;
    const domain_t dr = (b - a) / (2.*bins);
    typename result_type<F>::type I2(0), I4(0);
    
    for(unsigned i = 0; i < bins; ++i) {
        domain_t pos = a + (2*i+1.)*dr;
        I4 += func(pos);
        I2 += func(pos+dr);
    }
    
    return (func(a) + 2.*I2 + 4.*I4 - func(b)) * (dr/3.);
}

#endif
