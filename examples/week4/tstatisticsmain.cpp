#include <iostream>
#include "tstatistics.hpp"

using namespace std;

int main (int, char**)
{
  typedef Statistics<int> statistics_t;
  
  statistics_t s;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    statistics_t::value_type x;
    cin >> x;
    s.add(x);
  }
  cout << "Result: " << s.mean() << " +/- " << s.stddev() << endl;
}

