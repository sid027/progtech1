#include <iostream>
#include <chrono>

int main()
{
  int vec[10];

  std::chrono::time_point< std::chrono::high_resolution_clock > start , stop;
	
  start = std::chrono::high_resolution_clock::now();

  for( unsigned int i = 0 ; i < 10 ; i++ )
	vec[i] = 1;

  stop = std::chrono::high_resolution_clock::now();

  std::chrono::duration< double > time = stop - start;
  std::cout << "Loop took: " << time.count() << " seconds." << std::endl;

  return 0;
}
