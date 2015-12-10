/* Programming Techniques for Scientific Simulations, HS 2014
 * Week 13 BONUS allowing for higher-order derivatives of single variable expressions
 */

#ifndef ALGO_DERIVATION
#define ALGO_DERIVATION

enum op {Add, Multiply};
typedef int default_int_type;

//********

template<class T>
class Constant
{
public:
  typedef Constant<default_int_type> derivative_type;

  Constant(const T v) : _val(v) {}
  T operator()(const T) const { return _val; }
  derivative_type derivative() const { return derivative_type(0); }
private:
  T _val;
};

template <class T>
Constant<T> constant(const T x)
{
  return Constant<T>(x);
}

//********

template <class T>
class Variable
{
public:
  typedef Constant<default_int_type> derivative_type;
  
  T operator()(const T x) const { return x; }
  derivative_type derivative() const { return derivative_type(1); }
};

//********

// forward declaration
template<class left, class right, op o>
class Expression;

// base template
template<class left, class right, op o>
struct Expression_helper {
};

// specialization for op==Add
template<class left, class right>
struct Expression_helper<left,right,Add> {
  typedef Expression<typename left::derivative_type, typename right::derivative_type, Add> derivative_type;
  
  static derivative_type derivative(left l, right r) {
    return derivative_type(l.derivative(),r.derivative());
  }
};

// specialization for op==Multiply
template<class left, class right>
struct Expression_helper<left,right,Multiply> {
  typedef Expression<Expression<typename left::derivative_type, right, Multiply>,
                     Expression<left, typename right::derivative_type, Multiply>, Add> derivative_type;
  
  static derivative_type derivative(left l, right r) {
    return derivative_type(Expression<typename left::derivative_type, right, Multiply>(l.derivative(),r),
                           Expression<left, typename right::derivative_type, Multiply>(l,r.derivative()));
  }
};

//********

template<class left, class right, op o>
class Expression
{
public:
  typedef typename Expression_helper<left,right,o>::derivative_type derivative_type;
  
  Expression(const left _l, const right _r) : l(_l), r(_r) { }
        
  template <class T>
  T operator()(const T x)
  {
    switch (o)
      {
      case Add:
        return l(x) + r(x);
      case Multiply:
        return l(x) * r(x);
      }
  }
  
  derivative_type derivative() { // taking derivative without evaluation, returning expression template
    return Expression_helper<left,right,o>::derivative(l,r);
  }
        
private:
  left l;
  right r;
};

//********

template<class L, class R>
Expression<L, R, Multiply> operator*(const L l, const R r)
{
  return Expression<L, R, Multiply>(l, r);
}

template<class L, class R>
Expression<L, R, Add> operator+(const L l, const R r)
{
  return Expression<L, R, Add>(l, r);
}

#endif //ALGO_DERIVATION
