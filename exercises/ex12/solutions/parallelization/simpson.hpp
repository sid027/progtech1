/* Programming Techniques for Scientific Simulations, HS 2015
 * Exercise 12
 */

#ifndef SIMPSON_HPP
#define SIMPSON_HPP

#include <cstdlib>
#include <cassert>

/// F needs to be a function object
///     taking a single argument convertible from T
///     with return value convertible to T
/// T needs to be CopyConstructible, Assignable, 
///     shall support arithmetic operations with double with
///     result convertible to T with limited relative truncation errors
template<class F, typename T>
T integrate(const T a, const T b, const unsigned bins, const F& func)
{
  assert(bins > 0);
  
  const T dr = (b - a) / (2.*bins);
  T I2(0), I4(0);
  T pos = a;
  
  for(unsigned i = 0; i < bins; ++i) {
    pos += dr;
    I4 += func(pos);
    pos += dr;
    I2 += func(pos);
  }
  
  return (func(a) + 2.*I2 + 4.*I4 - func(b)) * (dr/3.);
}

#endif
