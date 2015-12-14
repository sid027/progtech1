#ifndef FISHING_POPULATION_HPP
#define FISHING_POPULATION_HPP

#include "population.hpp"

namespace Penna
{

  /**
   * Population of animals with fishing.
   */
  class FishingPopulation : public Population
  {
  public:
    /**
     * Constructor.
     * @param nmax Maximum population size. Parameter N_{max} in Penna's paper.
     * @param n0 Initial population size.
     * @param frate: Percentage of fish caught.
     * @param fage: Minimum age for removal by fishing.
     */
    FishingPopulation(const std::size_t nmax, const std::size_t n0, const double frate=0, const std::size_t fage=0);
    
    void change_fishing(const double frate, const std::size_t fage=0);
    
    /// Simulate one time step (year).
    void step();
    
  private:
    double frate_;
    std::size_t fage_;
  };

} // end namespace Penna

#endif // !defined FISHING_POPULATION_HPP
