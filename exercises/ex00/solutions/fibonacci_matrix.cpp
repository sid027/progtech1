/* Example code written by Jakub Imriska, ITP, ETH Zurich, 2014
 * for the lecture Programming Techniques for Scientific Simulations I (HS 14)
 * for c++ basics catch-up exercise
 */

/// NOTE: for n>93, the program does not work correctly due to integer overflow

#include<iostream>

struct integer_2x2_matrix {
  unsigned long long entry00, entry01, entry10, entry11;
  void set_to_identity() { entry00=1; entry01=0; entry10=0; entry11=1; }
};

integer_2x2_matrix matrix_multiplication(const integer_2x2_matrix& A, const integer_2x2_matrix& B) {
  integer_2x2_matrix C;
  C.entry00 = A.entry00*B.entry00 + A.entry01*B.entry10;
  C.entry01 = A.entry00*B.entry01 + A.entry01*B.entry11;
  C.entry10 = A.entry10*B.entry00 + A.entry11*B.entry10;
  C.entry11 = A.entry10*B.entry01 + A.entry11*B.entry11;
  return C;
}

unsigned long long Fibonacci(unsigned n) {
  /// we use recursive relation f(i) = f(i-1) + f(i-2)
  /// in matrix form: {{f(i-1)}, {f(i)}} = M . {{f(n-2)}, {f(n-1)}}
  ///   with M = {{0, 1}, {1, 1}}
  /// which allows to express f(n) as: {{f(n-1)}, {f(n)}} = M^(n-1) . {{f(0)}, {f(1)}}
  /// we compute the M^(n-1) in O(log(n)) steps
  /// NOTE: with floating point arithmetics we could diagonalize M and obtain the results in a single step
  if (n==0) return 0;
  if (n==1) return 1;
  integer_2x2_matrix M_to_n_minus_1, M_to_2_to_i;
  M_to_n_minus_1.set_to_identity();
  M_to_2_to_i.entry00=0;  M_to_2_to_i.entry01=1;
  M_to_2_to_i.entry10=1;  M_to_2_to_i.entry11=1;
  n--;
  while (n>0) {
    if (n%2==1) M_to_n_minus_1 = matrix_multiplication(M_to_n_minus_1,M_to_2_to_i);
    n/=2;
    M_to_2_to_i = matrix_multiplication(M_to_2_to_i,M_to_2_to_i);
  }
  return M_to_n_minus_1.entry11;
}

int main() {
  unsigned n;
  /// read input
  std::cout<<"The program will compute the Fibonacci(n). Set n: ";
  std::cin>>n;
  
  /// compute Fibonacci(n)
  std::cout<<"Fibonacci("<<n<<") = "<<Fibonacci(n)<<std::endl;
  
  return 0;
}
