#include <iostream>
#include <vector>
#include <omp.h>

int main()
{
    unsigned long const N = 1e7;
    std::vector<int> a(N, 1), b(N, 2), c(N);
    
#pragma omp parallel
    {
        for (int n=0; n<1000; ++n) {
            int t = omp_get_thread_num();
            int nthreads = omp_get_num_threads();
            
            long double const step = (N+0.5l) /  nthreads;
            int stop = (t+1) * step;
            for (std::size_t i = t * step; i < stop; ++i)
                c[i] = a[i] + b[i];
        }
    }
}