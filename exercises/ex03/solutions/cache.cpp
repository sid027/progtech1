/* Programming Techniques for Scientific Simulations, HS 2015
 * Exercise 3.2
 */

#include <vector>
#include <iostream>
#include <iomanip>
#include <chrono>

typedef int array_t;

int main()
{    
  const size_t elm_size = sizeof(array_t);
  const size_t MINSIZE = 8 / elm_size;
  const size_t MAXSIZE = 18 * 1024 * 1024 / elm_size;
  const size_t MAXSTEP = 256 / elm_size;
  const size_t NOPS    = 4 * MAXSIZE;
        
  array_t* arr = new array_t[MAXSIZE];
  for (size_t N=MINSIZE; N<MAXSIZE; N*=2) {
    for(size_t step=1; step<=std::min(MAXSTEP,N/4); step*=2) {
            
      const size_t num_steps = 4 * N / (4*step);
      const size_t num_sweeps = NOPS / num_steps;
            
      for( size_t i = 0; i < N; i += step )
        arr[i] = 0;
            
      std::chrono::time_point< std::chrono::high_resolution_clock > start , stop;
      start = std::chrono::high_resolution_clock::now();
      
      for( size_t sweep = 0; sweep < num_sweeps; ++sweep )
        {
          for( array_t* p = arr; p < arr+N; p += step )
            ++(*p);
        }
            
      stop = std::chrono::high_resolution_clock::now();
      const double time = static_cast<std::chrono::duration<double> >(stop-start).count();
      const double mops = num_steps * num_sweeps / (time * 1e6);
            
      std::cout << std::setprecision(12)
		<< std::setw(16) << double(N * elm_size) / 1024
		<< std::setw(16) << step * elm_size
		<< std::setw(16) << time
		<< std::setw(16) << mops
		<< std::endl;
    }
  }
    
  delete[] arr;
    
  return 0;
}
