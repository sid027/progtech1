#ifndef ITERATOR_HPP_
#define ITERATOR_HPP_
#include <cassert>
#include <cstdlib>
 
/* Bidirectional Iterator Requirements:

Iterator:
- CopyConstructible.
- CopyAssignable.
- Destructible.
- Supports: *a. (Dereferenceable)
- Supports: ++a. (Preincrementable)
	
Input Iterator:
- All requirements of an iterator.
- Supports: ==. (EqualityComparable)
- Supports: !=. 
- Supports: ->.
- Supports: a++. (Postincrementable)

Forward Iterator:
- All requirements of an input iterator.
- DefaultConstructible.
- Supports expression: *a++.

Bidirectional Iterator:
- All requirements of a forward iterator.
- Predecrementable.
- Postdecrementable.
- Supports expression: *a--.

*/

template<typename T>
class BiIterator
{
public:
	typedef T value_type;
	typedef T& reference;

	BiIterator();
        BiIterator( value_type* const , value_type* const , value_type* const );

	reference operator* () const;
	BiIterator<value_type>& operator++ ();

	bool operator== ( const BiIterator<value_type>& ) const;
	bool operator!= ( const BiIterator<value_type>& ) const;
	value_type* operator-> () const;
	BiIterator<value_type> operator++(int);

	/* Bidirectional iterator requirements */
	BiIterator<value_type>& operator--();
	BiIterator<value_type> operator--(int);

private:
	value_type* pcurr_;
	value_type* pbegin_; 	// pointer to the beginning
	value_type* pend_;		// pointer "one-past" the end
	
	void check( bool dereferenceable = true ) const;
	
	/* Grant private acccess to testing unit */
	friend struct iterator_unit_tests;
};

template<typename T>
void BiIterator<T>::check( bool dereferenceable ) const	
{	
	if( dereferenceable )
		assert( pbegin_ != NULL && pend_ != NULL && pcurr_ != NULL && pcurr_ >= pbegin_ && pcurr_ < pend_ ? true : false );
	else
		assert( pbegin_ != NULL && pend_ != NULL && pcurr_ != NULL && pcurr_ >= pbegin_ && pcurr_ <= pend_ ? true : false );
}

template<typename T>
BiIterator<T>::BiIterator(): pcurr_(NULL), pbegin_(NULL), pend_(NULL) {}

template<typename T>
BiIterator<T>::BiIterator( T* const pcurr_in , T* const pbegin_in , T* const pend_in ): pcurr_(pcurr_in), pbegin_(pbegin_in), pend_(pend_in) { check( false ); }

template<typename T>
typename BiIterator<T>::reference BiIterator<T>::operator*() const
{
	check();
	
	return *pcurr_;
}

template<typename T>
BiIterator<T>& BiIterator<T>::operator++()
{
	check();
	
	++pcurr_;
	
	return *this;
}

template<typename T>
bool BiIterator<T>::operator== ( const BiIterator<T>& ia ) const
{
	return pcurr_ == ia.pcurr_ && pbegin_ == ia.pbegin_ && pend_ == ia.pend_ ? true : false;
}

template<typename T>
bool BiIterator<T>::operator!= ( const BiIterator<T>& ia ) const
{
	return !((*this) == ia);
}

template<typename T>
typename BiIterator<T>::value_type* BiIterator<T>::operator->() const
{
	check();
	
	return pcurr_;
}

template<typename T>
BiIterator<T> BiIterator<T>::operator++(int)
{
	check();
	
	BiIterator<T> out(*this);
	++pcurr_;
	
	
	return out;
}

template<typename T>
BiIterator<T>& BiIterator<T>::operator--()
{
	check( false ); //Should only be valid before
	
	--pcurr_;
	
	check(); // should also be dereferenceable after
	
	return *this;
}

template<typename T>
BiIterator<T> BiIterator<T>::operator--(int)
{
	check( false ); //Should only be valid before
	
	BiIterator<T> out(*this);
	--pcurr_;
	
	check(); // should also be dereferenceable after
  
	return out;
}


#endif 
