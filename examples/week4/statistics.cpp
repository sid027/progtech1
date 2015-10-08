// copyright (c) 1998 Matthias Troyer, ETH Zurich
// this is free software
#include <cmath>
#include "statistics.hpp"

using namespace std;

Statistics::Statistics ()
  : sum1(0), sum2(0), n(0)
{}

//Statistics::Statistics (const Statistics& s)
//  : sum1(s.sum1), sum2(s.sum2), n(s.n)
//{
//}

//Statistics::~Statistics ()
//{}

//Statistics& Statistics::operator = (const Statistics& rhs)
//{
//  sum1 = rhs.sum1;
//  sum2 = rhs.sum2;
//  n = rhs.n;

//  return *this;
//}

void Statistics::add (Statistics::value_type value)
{
  sum1 += value;
  sum2 += (value * value);
  n++;
}

Statistics::size_type Statistics::number () const
{
  return n;
}

Statistics::value_type Statistics::mean () const
{
  return sum1 / n;
}

Statistics::value_type Statistics::stddev () const
{
  return sqrt((sum2 - sum1 * sum1 / n) / (n - 1));
}

