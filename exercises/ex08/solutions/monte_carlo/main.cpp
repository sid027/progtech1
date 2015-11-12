/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 10.1
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <random>

class PiStatistics
{
public:
    PiStatistics() : hits_(0), total_shots_(0) {}
    void new_shot(const double x, const double y)
    {
        ++total_shots_;
        if (x*x+y*y<1.0)   // we are using quarter of a circle
            ++hits_;
    }
    friend std::ostream& operator<<(std::ostream&, const PiStatistics&);
private:
    unsigned long hits_, total_shots_;
};

std::ostream& operator<<(std::ostream& os, const PiStatistics& stat)
{
    double mean = static_cast<double>(stat.hits_)/stat.total_shots_;

    // We don't need to measure the mean of squares <O^2> because the
    // only possible values are 0,1, therefore O=O^2.
    // error = sqrt( (<O^2> - <O>^2) / (N-1) )
    //         sqrt( (<O>   - <O>^2) / (N-1) )
    double error = std::sqrt(mean*(1.-mean)/(stat.total_shots_-1.));
    return os<<4.*mean<<"\t"<<4.*error;
}


int main()
{
    typedef std::mt19937 base_generator_type;
    
    base_generator_type generator;
    std::uniform_real_distribution<> dist(0, 1);
    
    const unsigned random_seed(8);

    generator.seed(random_seed);
    srand48(random_seed);
    std::cout << "# Random seed: " << random_seed << std::endl;
  
    PiStatistics pi_drand48;
    PiStatistics pi_mt19937;
    
    const unsigned checkpoints(128);
    const unsigned max_shots(128*1024*1024);
    std::cout<<"# number_of_trials\testimate_by_drand48\testimate_by_mt19937"<<std::endl;
    std::cout.precision(12);
    for (unsigned i=0; i<max_shots; ++i) {
        pi_drand48.new_shot(drand48(),drand48());
        pi_mt19937.new_shot(dist(generator),dist(generator));
        if ((i+1)%(max_shots/checkpoints)==0) {
            std::cout<<i<<"\t"<<pi_drand48<<"\t"<<pi_mt19937<<std::endl;
        }
    }
    
    return 0;
}
