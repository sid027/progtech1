/* Programming Techniques for Scientific Simulations, HS 2014
 * Exercise 11.2
 */

#include <vector>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <algorithm>
#include <chrono>


typedef double value_type;
typedef std::vector<value_type> matrix_type;
typedef matrix_type::size_type size_type;

void set(matrix_type& A, matrix_type& B, const size_type n);
void print(const matrix_type& A, const size_type n);

typedef void (*mult_function)(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n);
double benchmark(mult_function f, size_type n_iterations, matrix_type& A, matrix_type& B, matrix_type& C, const size_type n);

void mult(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n);
void mult1(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n);
void mult2(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n);
void mult3(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n);
void mult4(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n);
void mult5(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n);

extern "C"
{
  // Implements C = alpha*A*B + beta*C
  void dgemm_(const char& TRANSA , const char& TRANSB,
              const int& M, const int& N, const int& K,
              const double& alpha , const double* A, const int& LDA,
              const double* B, const int& LDB,
              const double& beta , double* C, const int& LDC) ;
}

int main()
{
#ifndef NDEBUG
  const size_type n = 8;
#else
  const size_type n = 2048;
#endif
  int n_iterations = 1;
  
  matrix_type A(n*n), B(n*n), C(n*n);
  
#ifndef NDEBUG
  set(A,B,n);
  print(A, n);
  std::cout << "*" << std::endl;
  print(B, n);
#endif
  
  std::stringstream ss;
  ss << n;
  
  std::cout << "mult..." << std::endl;
  ss << "\t" << benchmark(mult,n_iterations,A,B,C,n);
  
  std::cout << "mult1..." << std::endl;
  ss << "\t" << benchmark(mult1,n_iterations,A,B,C,n);
  
  std::cout << "mult2..." << std::endl;
  ss << "\t" << benchmark(mult2,n_iterations,A,B,C,n);
  
  std::cout << "mult3..." << std::endl;
  ss << "\t\t" << benchmark(mult3,n_iterations,A,B,C,n);
  
  std::cout << "mult4..." << std::endl;
  ss << "\t\t" << benchmark(mult4,n_iterations,A,B,C,n);

  std::cout << "mult5..." << std::endl;
  ss << "\t\t" << benchmark(mult5,n_iterations,A,B,C,n);
  
  std::cout << "** RESULTS **" << std::endl;
  std::cout << "N\ttrivial\tjki\ttranspose\tpointers+jki\tblocking\tblas" << std::endl;
  std::cout << ss.str() << std::endl;
}

double benchmark(mult_function f, size_type n_iterations, matrix_type& A, matrix_type& B, matrix_type& C, const size_type n)
{
  set(A,B,n);
  
  std::chrono::time_point< std::chrono::high_resolution_clock > t_start, t_end;
  t_start = std::chrono::high_resolution_clock::now();
  for (size_type i = 0; i < n_iterations; ++i) {
    f(A, B, C, n);
  }
  t_end = std::chrono::high_resolution_clock::now();
  
#ifndef NDEBUG
  std::cout << "C = " << std::endl;
  print(C, n);
#endif
  
  return static_cast<std::chrono::duration<double> >(t_end - t_start).count();
}

void set(matrix_type& A, matrix_type& B, const size_type n)
{
  srand48(42);
  for (size_type i=0; i<n; ++i) {
    for (size_type j=0; j<n; ++j) {
      A[i+j*n] = int(drand48()*2);
      B[i+j*n] = int(drand48()*2);
    }
  }
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


// Trivial implementation
void mult(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n)
{
  for (size_type i=0; i<n; ++i) {
    for (size_type j=0; j<n; ++j) {
      C[i+j*n] = 0;
      for (size_type k=0; k<n; ++k) {
        C[i+j*n] += A[i+k*n] * B[k+j*n];
      }
    }
  }
}

// Inverting loops for cache effects
void mult1(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n)
{
  for (size_type i = 0; i < n*n; ++i)
    C[i] = 0;
  
  for (size_type j = 0; j < n; j++)
    for (size_type k = 0; k < n; ++k)
      for (size_type i = 0; i < n; ++i)
        C[i+j*n] += A[i+k*n]*B[k+j*n];
}

// Using transpose for linear access in last loop + reduction in local variable
void mult2(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n)
{
  matrix_type D(n*n);
  for (size_type i = 0; i < n; ++i)
    for (size_type j = 0; j < n; ++j)
      D[i+j*n] = A[j+i*n];
  
  for (size_type i = 0; i < n; ++i) {
    for (size_type j = 0; j < n; ++j) {
      value_type out = 0;
      const value_type *in1 = &D[i*n], *in2 = &B[j*n];
      for (size_type k = 0; k < n; ++k, ++in1, ++in2)
        out += (*in1) * (*in2); // C[i+j*n] += D[k+i*n] * B[k+j*n];
      C[i+j*n] = out;
    }
  }
}

// Inverse loop orders + moving index computations out of inner loop
void mult3(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n)
{
  for (size_type j=0; j<n; ++j)  {
    std::fill(C.begin()+j*n,C.begin()+(j+1)*n,0);
    for (size_type k=0; k<n; ++k) {
      const value_type  b =  B[k+j*n];
      const value_type* a = &A[0+k*n];
      value_type      * c = &C[0+j*n];
      for (size_type i=0; i<n; ++i, ++a, ++c)
        *c += *a * b; // C[i+j*n] += A[i+k*n] * B[k+j*n];
    }
  }
}

#ifndef block_size
#define block_size 512
#endif

// Blocking
void mult4(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n)
{
  matrix_type D(4*4);
  std::fill(C.begin(),C.begin()+n*n,0);
  for (size_type j0 = 0; j0 < n; j0+=block_size)
    for (size_type k0 = 0; k0 < n; k0+=block_size)
      for (size_type i0 = 0; i0 < n; i0+=block_size)
	{
	  const size_type imax = std::min(i0+block_size,n), jmax = std::min(j0+block_size,n),
	    kmax = std::min(k0+block_size,n);
	  for (size_type j=j0; j < jmax ; ++j)
	    for (size_type k=k0; k < kmax ; ++k)
	      for (size_type i=i0; i < imax ; ++i)
	  	C[i+j*n] += A[i+k*n]*B[k+j*n];
	}
}

// BLAS DGEMM
void mult5(const matrix_type& A, const matrix_type& B, matrix_type& C, const size_type n)
{
  value_type one=1, zero=0;
  
  dgemm_('N', 'N',
         n, n, n,
         one, &A[0], n,
         &B[0], n,
         zero, &C[0], n);
}
