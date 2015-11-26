/* Programming Techniques for Scientific Simulations, HS 2015
 * Week 10.1
 */

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <algorithm>
#include <chrono>


inline void set(double *A, double *B, const int n) {
  srand48(42);
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      A[i*n+j] = int(drand48()*2);
      B[i*n+j] = int(drand48()*2);
    }
  }
}

inline void print(const double *A, const int n) {
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      std::cout << A[i*n+j] << " ";
    }
    std::cout << std::endl;
  }
}

// the naive implementation
inline void multiply_simple(const double *A, const double *B, double *C, const int n) {
  for (int i=0; i<n; ++i) {
    for (int j=0; j<n; ++j) {
      C[i*n+j] = 0;
      for (int k=0; k<n; ++k)
        C[i*n+j] += A[i*n+k] * B[k*n+j];
    }
  }   
}

// optimal out of simple implementations
inline void multiply(const int N, const double *A, const int LDA, const double *B, const int LDB, double *C, const int LDC) {
  /// for square blocks N x N of matrices A, B and C in column-major style with leading dimensions LDA, LDB and LDC
  double elem;
  for (int i=0; i<N; ++i) {
    std::fill(C+i*LDC, C+i*LDC+N, 0);
    for (int j=0; j<N; ++j) {
      elem=A[i*LDA+j];
      for (int k=0; k<N; ++k)
        C[i*LDC+k] += elem * B[j*LDB+k];
    }
  }
}

inline void add(const int N, const int M, const double *A, const int LDA, const double* B, const int LDB, double* C, const int LDC) {
  /// performs addition of a block N*M of matrices A and B
  for (int i=0; i<N; ++i)
    for (int j=0; j<M; ++j)
      C[i*LDC+j]=A[i*LDA+j]+B[i*LDB+j];
}

inline void diminish(const int N, const int M, const double *A, const int LDA, const double* B, const int LDB, double* C, const int LDC) {
  /// on a block N*M of matrices A and B performs diminishing
  for (int i=0; i<N; ++i)
    for (int j=0; j<M; ++j)
      C[i*LDC+j]=A[i*LDA+j]-B[i*LDB+j];
}

void multiply_Strassen(const int N, const double *A, const int LDA, const double *B, const int LDB, double *C, const int LDC) {
  /// for square blocks N x N of matrices A, B and C in column-major style with leading dimensions LDA, LDB and LDC
  /// simple implementation which runs optimal for N=M*2^n with M less than roughly 100
  if (N%2==0 && N>64) {
    const int n_half=N/2;
    double* Q1=new double[n_half*n_half];
    double* Q72=new double[n_half*n_half];
    double* Q43=new double[n_half*n_half];
    double* Q56=new double[n_half*n_half];
    double* helper=new double[n_half*n_half];
    
    // compute Q1
    add(n_half,n_half,A,LDA,A+n_half*LDA+n_half,LDA,helper,n_half);
    add(n_half,n_half,B,LDB,B+n_half*LDB+n_half,LDB,Q72,n_half);
    multiply_Strassen(n_half,helper,n_half,Q72,n_half,Q1,n_half);
    
    // compute Q7
    diminish(n_half,n_half,A+n_half,LDA,A+n_half*LDA+n_half,LDA,helper,n_half);
    add(n_half,n_half,B+n_half*LDB,LDB,B+n_half*LDB+n_half,LDB,Q43,n_half);
    multiply_Strassen(n_half,helper,n_half,Q43,n_half,Q72,n_half);
    
    // compute Q4
    diminish(n_half,n_half,B+n_half*LDB,LDB,B,LDB,helper,n_half);
    multiply_Strassen(n_half,A+n_half*LDA+n_half,LDA,helper,n_half,Q43,n_half);
    
    // compute Q5
    add(n_half,n_half,A,LDA,A+n_half,LDA,helper,n_half);
    multiply_Strassen(n_half,helper,n_half,B+n_half*LDB+n_half,LDB,Q56,n_half);
    
    // get c_11
    for (int i=0; i<n_half; ++i)
      for (int j=0; j<n_half; ++j)
        C[i*LDC+j]=Q1[i*n_half+j]+Q43[i*n_half+j]+Q72[i*n_half+j]-Q56[i*n_half+j];
    
    // compute Q2
    add(n_half,n_half,A+n_half*LDA,LDA,A+n_half*LDA+n_half,LDA,helper,n_half);
    multiply_Strassen(n_half,helper,n_half,B,LDB,Q72,n_half);
    
    // get c_21
    add(n_half,n_half,Q72,n_half,Q43,n_half,C+n_half*LDC,LDC);
    
    // compute Q3
    diminish(n_half,n_half,B+n_half,LDB,B+n_half*LDB+n_half,LDB,helper,n_half);
    multiply_Strassen(n_half,A,LDA,helper,n_half,Q43,n_half);
    
    // get c_12
    add(n_half,n_half,Q56,n_half,Q43,n_half,C+n_half,LDC);
    
    // compute Q6
    for (int i=0; i<n_half*n_half; ++i)
      Q1[i]+=Q43[i]-Q72[i];
    add(n_half,n_half,B,LDB,B+n_half,LDB,helper,n_half);
    diminish(n_half,n_half,A+n_half*LDA,LDA,A,LDA,Q72,n_half);
    multiply_Strassen(n_half,Q72,n_half,helper,n_half,Q56,n_half);
    
    // get c_22
    add(n_half,n_half,Q1,n_half,Q56,n_half,C+n_half*LDC+n_half,LDC);
    
    delete[] Q1;
    delete[] Q72;
    delete[] Q43;
    delete[] Q56;
    delete[] helper;
  } else {
    multiply(N, A, LDA, B, LDB, C, LDC);
  }
}


int main() {

#ifndef NDEBUG
  const int n = 8;
  int n_iterations = 1;
#else
  const int n = 2048;
  int n_iterations = 1;
#endif
  
  double *A = new double[n * n];
  double *B = new double[n * n];
  double *C1 = new double[n * n];
  double *C2 = new double[n * n];
  
  set(A, B, n);
  
#ifndef NDEBUG
  print(A, n);
  std::cout << "*" << std::endl;
  print(B, n);
#endif
  
  std::chrono::time_point< std::chrono::high_resolution_clock > t_start, t_end;
  std::stringstream ss;
  

  t_start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < n_iterations; ++i) {
    multiply(n, A, n, B, n, C1, n);
  }
  t_end = std::chrono::high_resolution_clock::now();
  ss << n << "\t\t" << static_cast<std::chrono::duration<double> >(t_end - t_start).count();
#ifndef NDEBUG
  std::cout << "C1 = " << std::endl;
  print(C1, n);
#endif

  t_start = std::chrono::high_resolution_clock::now();
  for (int i = 0; i < n_iterations; ++i) {
    multiply_Strassen(n, A, n, B, n, C2, n);
  }
  t_end = std::chrono::high_resolution_clock::now();
  ss << "\t\t" << static_cast<std::chrono::duration<double> >(t_end - t_start).count();
#ifndef NDEBUG
  std::cout << "C2 = " << std::endl;
  print(C2, n);
#endif

  diminish(n,n,C1,n,C2,n,A,n);
#ifndef NDEBUG
  std::cout<<"C2 - C1 ="<<std::endl;
  print(A, n);
#endif
  for (int i=0; i<n*n; ++i)
    if (A[i]!=0)
      throw std::runtime_error("Results C2 and C1 not same!");
  
  
  std::cout << "** RESULTS **" << std::endl;
  std::cout << "Matrix_size\tmultiply\tmultiply_Strassen" << std::endl;
  std::cout << ss.str() << std::endl;
  
  delete[] A;
  delete[] B;
  delete[] C1;
  delete[] C2;
}
