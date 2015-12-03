#include <iostream>
#include <vector>
#include <omp.h>

int main()
{
    unsigned long const N = 1e7;
    std::vector<int> a(N, 1), b(N, 2), c(N);
    
    for (int n=0; n<1000; ++n)
        for (std::size_t i = 0; i < N; ++i)
            c[i] = a[i] + b[i];
}