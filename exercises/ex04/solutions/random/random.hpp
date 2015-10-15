#ifndef RANDOM_HPP
#define RANDOM_HPP

class Generator
{
public:
  using result_type = unsigned;
    
  Generator(result_type seed=42);
  result_type generate();
  result_type max() const;
    
private:
  typedef unsigned impl_type;
  impl_type seed_;
    
  const impl_type a_;
  const impl_type c_;
  const impl_type m_;
};

#endif // !defined RANDOM_HPP
