#include <iostream>
#include "statistics.hpp"

using namespace std;

int main (int, char**)
{
  Statistics s;
  int n;
  cin >> n;      // first entry is size of sample
  for (int i = 0; i < n; i++) {
    double x;
    cin >> x;    // read in the individual numbers
    s.add(x);
  }
  cout << "Result: " << s.mean() << " +/- " << s.stddev() << endl;
}

