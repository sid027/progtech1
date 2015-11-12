#include <random>
#include <iostream>
#include <iomanip>
#include <map>

template<typename T1, typename T2>
void print_hist(std::map<T1,T2> hist)
{
  for (auto p : hist)
    std::cout << std::fixed << std::setprecision(1) << std::setw(2)
	      << p.first << ' ' << std::string(p.second/1000, '*') << '\n';
}

int main()
{
  std::mt19937 mt(42); // create an engine, initial seed 42
  
  // create four distributions
  std::uniform_int_distribution<int>     dist1(0,10);
  std::uniform_real_distribution<double> dist2(0.,10.);
  std::exponential_distribution<double>  dist3(.6);
  std::normal_distribution<double>       dist4(0.,2.);

  // distributions are called with the engine as argument to create random numbers
  std::cout << dist1(mt) << "\n";
  std::cout << dist2(mt) << "\n";
  std::cout << dist3(mt) << "\n";
  std::cout << dist4(mt) << "\n";

  // create some histograms
  std::map<int, int> hist1, hist2, hist3, hist4;
  for (int n = 0; n < 100000; ++n) {
    ++hist1[int(dist1(mt))];
    ++hist2[int(dist2(mt))];
    ++hist3[int(dist3(mt))];
    ++hist4[std::round(dist4(mt))];
  }

  std::cout << "uniform int distribution:\n";
  print_hist(hist1);
  std::cout << "uniform real distribution:\n";
  print_hist(hist2);
  std::cout << "exponential distribution:\n";
  print_hist(hist3);
  std::cout << "normal distribution:\n";
  print_hist(hist4);
  
  return 0;
}
