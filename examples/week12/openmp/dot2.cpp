#include <iostream>
#include <vector>
#include <omp.h>

int main()
{
    unsigned long const N = 1e5;
    std::vector<int> a(N, 2), b(N, 3);
    
    double sum = 0.;
#pragma omp parallel for
    for (std::size_t i = 0; i < N; ++i)
#pragma omp critical
        sum += a[i] * b[i];
    
    std::cout << "Dot product is " << sum << std::endl;
}
