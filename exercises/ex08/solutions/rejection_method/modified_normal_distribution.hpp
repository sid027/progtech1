/* Programming Techniques for Scientific Simulations, HS 2015
 * Exercise 8.2
 */

#ifndef MODIFIED_NORMAL_DISTRIBUTION_HPP
#define MODIFIED_NORMAL_DISTRIBUTION_HPP

#include <random>
#include <cmath>

template< class RealType = double >
class modified_normal_distribution
{
public:
  typedef typename std::normal_distribution<RealType>::result_type result_type;
  typedef RealType param_type;

  modified_normal_distribution(RealType p = 1) : p_(p), normal_distr_(0,1), distr01_(0,1), tries_(0), calls_(0) {}

  // operator for calling the distribution
  template< class REngine >
  result_type operator() (REngine& rnd) { return p_*get_x(rnd); }

  // calling the distribution and giving a parameter
  template< class REngine >
  result_type operator() (REngine& rnd, const param_type& p) { return p*get_x(rnd); }

  // return parameter
  param_type param() const { return p_; }
  // set parameter, also resets
  void param(const param_type& p) { p_=p; tries_=0; calls_=0; }
  // reset, resets the measurement of the acceptance ratio as well
  void reset() { normal_distr_.reset(); distr01_.reset(); tries_=0; calls_=0; }
  // min and max of the possible generated random numbers
  result_type min() const { return (p_==0 ? 0 : normal_distr_.min()); }
  result_type max() const { return (p_==0 ? 0 : normal_distr_.max()); }
  // relational operators
  bool operator== (const modified_normal_distribution& rhs) { return (p_==rhs.p_ && normal_distr_ == rhs.normal_distr_ && distr01_==rhs.distr01_); }
  bool operator!= (const modified_normal_distribution& rhs) { return (!this->operator==(rhs)); }

  // gives the acceptance ratio calculated during the calls after last reset()
  double acceptance_ratio() const { return static_cast<double>(calls_)/tries_; }

  template <class T> friend std::ostream& operator<< (std::ostream&, const modified_normal_distribution<T>&);
  template <class T> friend std::istream& operator>> (std::istream&, modified_normal_distribution<T>&);

private:
  result_type p_;
  std::normal_distribution<RealType> normal_distr_;
  std::uniform_real_distribution<RealType> distr01_;

  typedef unsigned long counting_type;
  counting_type tries_;
  counting_type calls_;

  RealType f_over_h_(const RealType&) const;

  template< class REngine >
  result_type get_x(REngine&);
};

template< class RealType >
template< class REngine >
typename modified_normal_distribution<RealType>::result_type modified_normal_distribution<RealType>::get_x(REngine& rnd)
{
  RealType try_value;
  ++calls_;
  do {
    try_value = normal_distr_(rnd);
    ++tries_;
  } while (distr01_(rnd) > f_over_h_(try_value) );
  return try_value;
}

template< class RealType>
RealType modified_normal_distribution<RealType>::f_over_h_(const RealType& x) const
{
  RealType c=std::cos(x);
  return c*c;
}

template< class RealType>
std::ostream& operator<< (std::ostream& os, const modified_normal_distribution<RealType>& mnd)
{
  return os << mnd.p_ << mnd.normal_distr_ << mnd.distr01_;
}

template< class RealType>
std::istream& operator>> (std::istream& is, modified_normal_distribution<RealType>& mnd)
{
  return is >> mnd.p_ >> mnd.normal_distr_ >> mnd.distr01;
}

#endif  // MODIFIED_NORMAL_DISTRIBUTION_HPP
