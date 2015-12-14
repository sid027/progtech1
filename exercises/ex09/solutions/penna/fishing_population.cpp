#include "fishing_population.hpp"
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>

namespace Penna 
{
        
  extern std::mt19937 rng;

  FishingPopulation::FishingPopulation(const std::size_t nmax, const std::size_t n0, const double frate, const std::size_t fage)
    :Population(nmax, n0)
    ,frate_(frate)
    ,fage_(fage)
  {}

  void FishingPopulation::change_fishing(const double frate, const std::size_t fage)
  {
    frate_=frate;
    fage_=fage;
  }

  class FishingPredicate
  {
  public:
    FishingPredicate(const double probability, const std::size_t minage)
      : probability_(probability), minage_(minage) {};
    bool operator()(const Fish& a ) const
    {
      std::uniform_real_distribution<double> distribution_01(0.0,1.0);
      return a.age() > minage_ && (probability_ >= 1. || distribution_01(rng) < probability_);
    };
    
  private:
    const double probability_;
    const std::size_t minage_;
  };
    
  void FishingPopulation::step()
  {
    // Do normal aging
    Population::step();
    
    // Fishing
    if(frate_ > 0)
      population_.remove_if( FishingPredicate( frate_, fage_ ) );
  }

} // end namespace Penna
