#ifndef PENNA_VECTOR_H
#define PENNA_VECTOR_H

#include <vector>

template <class T>
class penna_vector 
 : public std::vector<T> 
{
  typedef std::vector<T> base_type;
public:
  typedef typename base_type::value_type value_type;
  typedef typename base_type::reference reference;
  typedef typename base_type::const_reference const_reference;
  typedef typename base_type::iterator iterator;
  typedef typename base_type::const_iterator const_iterator;
  typedef typename base_type::reverse_iterator reverse_iterator;
  typedef typename base_type::const_reverse_iterator const_reverse_iterator;
  typedef typename base_type::size_type size_type;
  typedef typename base_type::difference_type difference_type;

  penna_vector(size_type s=0, value_type x=value_type()) : base_type(s,x) {}
  template <class IT>
  penna_vector(IT first, IT last) : base_type(first,last) {}

  template <class P>
  void remove_if(P pred)
  {
    iterator it=this->begin();
    while (it!=this->end())
    {
      if (pred(*it))
      {
        *it=this->back(); // copy the last to this location
        this->resize(this->size()-1); // remove the last one
      }
      else
        ++it;
    }
  }
};
  
#endif
