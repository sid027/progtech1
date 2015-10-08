// copyright (c) 1998 Matthias Troyer, ETH Zurich
// this is free software
#ifndef STATISTICS_H__
#define STATISTICS_H__

class Statistics {
public:
  typedef double value_type;
  typedef unsigned int size_type;

  Statistics ();
  //Statistics (const Statistics& s);
  //~Statistics ();
  //Statistics& operator = (const Statistics& rhs);

  void add (value_type value);
  size_type number () const;
  value_type mean () const;
  value_type stddev () const;
private:
  value_type sum1, sum2;
  size_type n;
};

#endif
