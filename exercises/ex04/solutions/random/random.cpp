#include <limits>
#include <cassert>
#include <iostream>

#include "random.hpp"
    
Generator::Generator(result_type seed) 
 : seed_(seed),
   a_(1664525),
   c_(1013904223),
   m_(static_cast<Generator::impl_type>(1ul<<32))
{
    // version 1:
    //assert(std::numeric_limits<impl_type>::max()>=a_*(m_-1)+c_);
    // version 2:
    //assert(std::numeric_limits<impl_type>::max()>=m_-1);
    // version 3:
    assert(32==std::numeric_limits<impl_type>::digits);
}

Generator::result_type Generator::max() const
{
  return m_ - 1;
}

    
Generator::result_type Generator::generate()
{
  // version 1: formula valid for any m_; impl_type shall in that case be able to represent the number a_*(m_-1)+c_
  // seed_ = (a_ * seed_ + c_) % m_;
  
  // version 2: if m_=2^k for an integer k, then we may replace the slow modulo operation (%) by a bitwise AND with (m_-1); requires std::numeric_limits<impl_type>::max()>=m-1
  //seed_ = (a_ * seed_ + c_) & (m_ - 1);
  
  // version 3: if m_=2^k and k==std::numeric_limits<impl_type>::digits then the truncation to the type impl_type will do the modulo operation automatically
  seed_ = a_ * seed_ + c_;
  
  return seed_;
}
