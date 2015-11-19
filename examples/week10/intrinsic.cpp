#include <iostream>
#include <nmmintrin.h>

int main()
{
  unsigned int x;
  std::cin >> x;
  unsigned int cnt = _mm_popcnt_u32(x);
  std::cout << x << " has " << cnt << " bits set\n";
}
