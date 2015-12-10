// Programming Techniques for Scientific Simulations, HS 2015
// Week 12
#include <iostream>
#include <cassert>
#include <limits>

typedef unsigned long long uint_t;

/// version emulating the behavior of the function combinatorial_number
namespace N_over_K {

  template<unsigned N, unsigned K, unsigned steps_to_do, uint_t tmp>
  struct helper {
    static uint_t eval() { 
      static_assert(tmp==(tmp*(N-K+steps_to_do))/(N-K+steps_to_do),"RangeError: Overflow");
      return helper<N,K,steps_to_do-1,tmp*(N-K+steps_to_do)/(1+K-steps_to_do)>::eval(); 
    }
  };

  template<unsigned N, unsigned K, uint_t tmp>
  struct helper<N,K,0,tmp> {
    static uint_t eval() { return tmp; }
  };

  template<unsigned N, unsigned K, bool K_larger_than_NminusK>
  struct helper1 {
    static uint_t eval() { return helper<N,K,K,1>::eval(); }
  };

  template<unsigned N, unsigned K>
  struct helper1<N,K,true> {
    static uint_t eval() { return helper<N,N-K,N-K,1>::eval(); }
  };

} // namespace N_over_K

template<unsigned N, unsigned K>
struct CombinatorialNumber{
  static uint_t eval() { return N_over_K::helper1<N,K,(K>(N-K))>::eval(); }
};


/// compact version
template<unsigned N, unsigned K>
struct CombinatorialNumber_compact{
  static uint_t eval() { return (K<=(N-K)) ? (N-K+1)*CombinatorialNumber_compact<N,K-1>::eval()/K : CombinatorialNumber_compact<N,N-K>::eval(); }
};
template<unsigned N>
struct CombinatorialNumber_compact<N,0> {
  static uint_t eval() { return 1; }
};


/// version which does overflow only when the actual result overflows
template<unsigned N, unsigned K>
struct CombinatorialNumber_vs2{
  static uint_t eval() { return CombinatorialNumber_vs2<N-1,K-1>::eval() + CombinatorialNumber_vs2<N-1,K>::eval(); }
};
template<unsigned N>
struct CombinatorialNumber_vs2<N,0> {
  static uint_t eval() { return 1; }
};
template<unsigned N>
struct CombinatorialNumber_vs2<N,N> {
  static uint_t eval() { return 1; }
};
template<>
struct CombinatorialNumber_vs2<0,0> {
  static uint_t eval() { return 1; }
};



/// function for checking purpose
uint_t combinatorial_number(const unsigned n, const unsigned k) {
  assert(k<=n);
  uint_t tmp(1);
  for (unsigned i=0; i<std::min(k,n-k); ++i) {
    tmp*=(n-i);
    tmp/=(i+1);
  }
  return tmp;
}


int main() {
  const unsigned N(0), K(0);
  std::cout << combinatorial_number(N,K) << std::endl;
  std::cout << CombinatorialNumber<N,K>::eval() << std::endl;
  std::cout << CombinatorialNumber_compact<N,K>::eval() << std::endl;
  std::cout << CombinatorialNumber_vs2<N,K>::eval() << std::endl;
  //std::cout << std::numeric_limits<uint_t>::max() << std::endl;
  return 0;
}
