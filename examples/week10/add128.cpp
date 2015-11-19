struct int128 {
  unsigned long long low;
  long long high;
};

int128 operator+(int128 x, int128 y) {
  int128 result;
  result.low=x.low+y.low;
  result.high=x.high+y.high; // does not use carry of previous addition
  return result;
}

