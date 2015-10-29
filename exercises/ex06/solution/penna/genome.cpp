#include "genome.hpp"
#include <random>

namespace Penna
{

std::mt19937 rng(13);

age_type Genome::mutation_rate_ = 2;
age_type Genome::bad_threshold_ = 2;

void Genome::set_mutation_rate( age_type m )
{
    mutation_rate_ = m; 
}

  void Genome::set_bad_threshold( age_type t )
{
     bad_threshold_ = t; 
}

age_type Genome::count_bad( age_type n ) const
{
    return (genes_<<(number_of_genes-n-1)).count();
}

age_type Genome::get_bad_threshold() const
  {
    return bad_threshold_;
  }

void Genome::mutate()
{
    std::uniform_int_distribution<age_type> distribution_for_genes(0,Genome::number_of_genes-1);
    
    // Mutate a random selection of M genes
    for( size_t i = 0; i < mutation_rate_; ++i )
        genes_.flip( distribution_for_genes(rng) );
}

} // end namespace Penna
