#include <cstdlib>

class RNG {
public:
  typedef double result_type;
  
  RNG() {}
  
  result_type min() const { return 0.;}
  result_type max() const { return 1.;}

  virtual void seed(long seedval) = 0;
  virtual result_type operator()() = 0;
  
};


class DRand : public RNG {
public:
  DRand() {}
  void seed(long seedval) { srand48(seedval);}
  result_type operator()() { return drand48();}
};

template <class Generator>
class ConcreteRNG : public RNG {
public:
  ConcreteRNG() : rng_() {}
  void seed(long seedval) { rng_.seed(seedval);}
  result_type operator()() { return rng_();}
private:
  Generator rng_;
};


