#include <iostream>
#include <limits>
#include "array.hpp"

// the second helper:
template<class T, bool F>
struct helper2 { typedef T type;};

// the second helper if the type is integer: a partial specialization"
template<class T>
struct helper2<T,true> { typedef double type;};

// the first helper:
template<class T, bool F>
struct helper1 { typedef T type;};

// the first helper if numeric_limits is defined: a partial specialization"
template<class T>
struct helper1<T,true> {
  typedef typename
  helper2<T, std::numeric_limits<T>::is_integer>::type type;
};
// helper1 gives the type
template <class T> struct average_type {
  typedef typename
  helper1<T, std::numeric_limits<T>::is_specialized>::type type;
};


template <class T>
typename average_type<T>::type
average(const Array<T>& v) {
 typename average_type<T>::type sum=0;
  for (int n=0;n<v.size();++n)
    sum += v[n];
  return sum/v.size();
}


int main() {
  std::size_t n=10;
  Array<double> v1(n,0);

  for(int i=0;i<n;++i) v1[i]=i;
  
  std::cout << "Average of double array: " << average(v1) << std::endl;

  Array<int> v2(n,0);
  
  for(int i=0;i<n;++i) v2[i]=i;
  
  std::cout << "Average of int array: " << average(v2) << std::endl;

  Array<short> v3(n,0);
  
  for(int i=0;i<n;++i) v3[i]=i;
  
  // automatic solution works for all integer types
  std::cout << "Average of short array: " << average(v3) << std::endl;

  return 0;
}
