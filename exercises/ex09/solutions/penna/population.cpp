#include "population.hpp"
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdlib>


namespace Penna
{

extern std::mt19937 rng;

Population::Population( size_t nmax, size_t n0 )
:   nmax_( nmax )
,   population_( n0 )
{
}

void Population::simulate( size_t time )
{
    while( time-- )
        step();
}

class DeathPredicate
{
public:
    DeathPredicate( double probability ) : probability_(probability) {};
    bool operator()( Fish const& a ) const
    {
        std::uniform_real_distribution<double> distribution_01(0,1);
        return probability_ >= 1. || a.is_dead() || distribution_01(rng) < probability_;
    };
    
private:
    double probability_;
};


void Population::step()
{
    // Age all fish
  std::for_each( population_.begin(), population_.end(), std::mem_fun_ref(&Fish::grow) );
  
  // Remove dead ones
  population_.remove_if( DeathPredicate( size() / double( nmax_ ) ) );
  
  // Generate offsprings
  std::vector<Fish> parents;
  std::remove_copy_if( population_.begin(), population_.end(), std::back_inserter(parents), std::not1( std::mem_fun_ref(&Fish::is_pregnant) ) );
  std::transform( parents.begin(), parents.end(), std::back_inserter(population_), std::mem_fun_ref(&Fish::give_birth) );
}

std::size_t Population::size() const
{
    return population_.size();
}

Population::const_iterator Population::begin() const
{
    return population_.begin();
}

Population::const_iterator Population::end() const
{
    return population_.end();
}

} // end namespace Penna
