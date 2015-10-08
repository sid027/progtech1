#ifndef TSTATISTICS_H__
#define TSTATISTICS_H__

#include <cmath>

template <class Real>
class Statistics {
public:

  typedef unsigned int size_type;
  typedef Real value_type;
  Statistics ();

  void add (value_type value);
  size_type number () const;
  value_type mean () const;
  value_type stddev () const;
private:
  value_type sum1, sum2;
  size_type n;
};

template <class Real>
Statistics<Real>::Statistics ()
  : sum1(0), sum2(0), n(0)
{}

template <class Real>
void Statistics<Real>::add (Real value)
{
  sum1 += value;
  sum2 += (value * value);
  n++;
}

template <class Real>
typename Statistics<Real>::size_type Statistics<Real>::number () const
{
  return n;
}

template <class Real>
Real Statistics<Real>::mean () const
{
  return sum1 / n;
}

template <class Real>
Real Statistics<Real>::stddev () const
{
  return std::sqrt((sum2 - sum1 * sum1 / n) / (n - 1));
}

#endif
