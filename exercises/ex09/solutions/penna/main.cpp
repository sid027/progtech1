#include "fishing_population.hpp"
#include "fish.hpp"
#include <string>
#include <random>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>

namespace Penna {extern std::mt19937 rng;}

std::vector<double> gene_histogram(const Penna::FishingPopulation& pop)
{
  std::vector<double> histo(Penna::Genome::number_of_genes);
  double n(pop.size());
  for( Penna::FishingPopulation::const_iterator a = pop.begin(); a != pop.end(); ++a ){
    for( Penna::age_type i = 0; i < histo.size(); ++i )
      histo[i] += a->genome().is_bad(i) / n;
  }
  return histo;
}


int main(int argc, const char** argv)
{
  if (!(argc==12 || argc==15)) {
    std::cout << "Usage: " << argv[0] << " [simulational time] [mutation rate M] "
              << "[bad threshold T] [reproduction age R] [pregnancy probability P] "
              << "[population limit Nmax] [initial population size N0] [num measurements] "
              << "[time at start of fishing 1] [fishing rate 1] [fishing age 1] "
              << "optional: [time at start of fishing 2] [fishing rate 2] [fishing age 2]"
              << std::endl;
    return -1;
  }
  std::size_t sim_time=std::stoul(argv[1]), mut_rate=std::stoul(argv[2]),bad_threshold=std::stoul(argv[3]),
              repr_age=std::stoul(argv[4]), nmax=std::stoul(argv[6]), n0=std::stoul(argv[7]), nmeas=std::stoul(argv[8]),
              fishing_1_start=std::stoul(argv[9]), fishing_age_1=std::stoul(argv[11]),
              fishing_2_start=argc>12?std::stoul(argv[12]):sim_time, fishing_age_2=argc>12?std::stoul(argv[14]):0;
  double pregnancy_prob=std::stod(argv[5]), fishing_rate_1=std::stod(argv[10]), fishing_rate_2=argc>12?std::stod(argv[13]):0.;

#ifdef NDEBUG
  Penna::rng.seed(time(NULL));  // use time for seeding of the pseudo random generator (for production runs)
#endif

  Penna::Genome::set_mutation_rate              ( mut_rate );
  Penna::Genome::set_bad_threshold              ( bad_threshold );
  Penna::Fish::set_maturity_age                 ( repr_age );

  std::cout << "## sim_time=" << sim_time << ", M=" << mut_rate << ", T=" << bad_threshold << ", R=" << repr_age
            << ", pregnancy_prob=" << pregnancy_prob << ", Nmax=" << nmax << ", N0=" << n0 << std::endl;
  std::cout << "## Penna::Fishing period 1: starts=" << fishing_1_start << ", rate=" << fishing_rate_1 << ", age>=" << fishing_age_1 << std::endl;
  if (argc>12)
    std::cout << "## Penna::Fishing period 2: starts=" << fishing_2_start << ", rate=" << fishing_rate_2 << ", age>=" << fishing_age_2 << std::endl;

  Penna::FishingPopulation pop(nmax,n0);
  std::cout << "# time\tN" << std::endl;
  std::size_t time = 0;
  for(; time < fishing_1_start; ++time ){
    pop.simulate( 1 );
    if (time%(sim_time/nmeas)==0)
      std::cout << time << "\t" << pop.size() << std::endl;
  }
  pop.change_fishing(fishing_rate_1,fishing_age_1);
  for(; time < fishing_2_start; ++time ){
    pop.simulate( 1 );
    if (time%(sim_time/nmeas)==0)
      std::cout << time << "\t" << pop.size() << std::endl;
  }
  pop.change_fishing(fishing_rate_2,fishing_age_2);
  for(; time < sim_time; ++time ){
    pop.simulate( 1 );
    if (time%(sim_time/nmeas)==0)
      std::cout << time << "\t" << pop.size() << std::endl;
  }

  std::vector<double> genes = gene_histogram(pop);
  std::ofstream genefile("gene_histogram.dat");
  std::copy(genes.begin(),genes.end(),std::ostream_iterator<double>(genefile,"\n"));

  return 0;
}
