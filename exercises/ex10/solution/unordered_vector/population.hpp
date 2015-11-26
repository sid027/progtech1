#ifndef POPULATION_HPP
#define POPULATION_HPP

#include "fish.hpp"
#include <list>
#include <random>
#include "penna_vector.hpp"

namespace Penna
{
  /**
   * Population of fishes.
   */
  class Population
  {
    // typedef std::list<Fish> container_type;
    typedef penna_vector<Fish> container_type;
    std::size_t nmax_;
    container_type population_;

  public:
    typedef container_type::const_iterator const_iterator;
    /**
     * Constructor.
     * @param nmax Maximum population size. Parameter N_{max} in Penna's paper.
     * @param n0 Initial population size.
     */
    Population( std::size_t nmax, std::size_t n0 );
    /// Classes with a vtable should have a virtual destructor.
    virtual ~Population() {};

    /// Simulate growth of the population for time years.
    void simulate( std::size_t time );

    /// Simulate one time step (year).
    virtual void step();

    /// Get size of population
    std::size_t size() const;

    /// Get iterators for the population_ container
    const_iterator begin() const;
    const_iterator end() const;
  };

} // end namespace Penna

#endif // !defined POPULATION_HPP
