#include "population.hpp"
#include "fish.hpp"
#include <iostream>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>
#include <random>

namespace Penna {extern std::mt19937 rng;}

std::vector<double> gene_histogram(const Penna::Population& pop)
{
  std::vector<double> histo(Penna::Genome::number_of_genes);
  double n = pop.size();
  for( Penna::Population::const_iterator a = pop.begin(); a != pop.end(); ++a )
    {
      for( Penna::age_type i = 0; i < histo.size(); ++i )
	histo[i] += a->genome().is_bad(i) / n;
    }
  return histo;
}


int main(int argc,const char** argv)
{
    if (argc!=8) {
        std::cout << "Usage: " << argv[0] << " [simulational time] [mutation rate M] "
                  << "[bad threshold T] [reproduction age R] "
                  << "[population limit Nmax] [initial population size N0] [num measurements]" << std::endl;
        return -1;
    }
    std::size_t sim_time=std::stoul(argv[1]), mut_rate=std::stoul(argv[2]),bad_threshold=std::stoul(argv[3]),
                repr_age=std::stoul(argv[4]), nmax=std::stoul(argv[5]), n0=std::stoul(argv[6]), nmeas=std::stoul(argv[7]);

#ifdef NDEBUG
    Penna::rng.seed(time(NULL));  // use time for seeding of the pseudo random generator (for production runs)
#endif

    Penna::Genome::set_mutation_rate            ( mut_rate );
    Penna::Genome::set_bad_threshold            ( bad_threshold );
    Penna::Fish::set_maturity_age               ( repr_age );

    std::cout << "## sim_time=" << sim_time << ", M=" << mut_rate << ", T=" << bad_threshold << ", R=" << repr_age
              << ", Nmax=" << nmax << ", N0=" << n0 << std::endl;

    Penna::Population pop( nmax, n0 );
    std::cout << "# time\tN" << std::endl;
    for( size_t i = 0; i < sim_time; ++i )
    {
        pop.simulate( 1 );
        if (i%(sim_time/nmeas)==0)
            std::cout << i << "\t" << pop.size() << std::endl;
    }
    
    std::vector<double> genes = gene_histogram(pop);
    std::ofstream genefile("gene_histogram.dat");
    std::copy(genes.begin(),genes.end(),std::ostream_iterator<double>(genefile,"\n"));

    return 0;
}
