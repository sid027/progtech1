/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 11.2
 */

#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <chrono>


typedef double value_type;
typedef std::vector<value_type> matrix_type;
typedef matrix_type::size_type size_type;

void set(matrix_type& A, const size_type n)
{
  for (size_type i=0; i<n*n; ++i)
    A[i] = drand48();
}

void multiply_simple(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n)
{
  // TO BE IMPLEMENTED ...
}

void print(const matrix_type& A, const size_type n)
{
  for (size_type i=0; i<n; ++i) {
    for (size_type j=0; j<n; ++j) {
      std::cout << A[i*n+j] << " ";
    }
    std::cout << std::endl;
  }
}

int main() 
{
  srand48(42);
  const size_type n = 1024;
  const unsigned num_iter = 8;

  matrix_type A(n*n), B(n*n), C(n*n);
  set(A,n);
  set(B,n);
  
  std::chrono::time_point< std::chrono::high_resolution_clock > t_start, t_end;
  t_start = std::chrono::high_resolution_clock::now();

  for (unsigned i = 0; i < num_iter; ++i)
    multiply_simple(A, B, C, n);

  t_end = std::chrono::high_resolution_clock::now();

  std::cout << n << " " << static_cast<std::chrono::duration<double> >(t_end - t_start).count()  << std::endl;
}
