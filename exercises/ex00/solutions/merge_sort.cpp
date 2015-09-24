/* Example code written by Jakub Imriska, ITP, ETH Zurich, 2014
 * for the lecture Programming Techniques for Scientific Simulations I (HS 14)
 * for c++ basics catch-up exercise
 */

#include<iostream>
#include<cmath>

void merge_sort(double sequence[], double* buffer, unsigned n) {
  /// precondition: length 'n' of sequence shall be n>=1, 'buffer' shall be at least of same length
  /// postcondition: the sequence 'sequence' of length 'n' will be sorted in-place
  if (n==1) return;
  /// split the work
  double* seq1=sequence;
  double* seq2=sequence+n/2;
  merge_sort(seq1,buffer,n/2);
  merge_sort(seq2,buffer+n/2,n-n/2);
  /// and merge it in buffer
  double* buf=buffer;
  while (seq1<sequence+n/2 && seq2<sequence+n) {
    if (*seq1<*seq2) *buf++ = *seq1++;
    else *buf++ = *seq2++;
  }
  while (seq1<sequence+n/2) *buf++ = *seq1++;
  /// copy sorted sequence in buffer to sequence
  while (buf-->buffer) *(sequence+(buf-buffer)) = *buf;
}

int main() {
  unsigned n;
  std::cout<<"Set length of the sequence to be sorted: ";
  std::cin>>n;
  
  /// generate a non-monotonic sequence of asked length and print it
  double* sequence = new double[n];  // allocate memory for the sequence
  std::cout<<"Original sequence: ";
  for (unsigned i=0; i<n; i++) {
    sequence[i] = sin(i);
    std::cout<<sequence[i]<<"  ";
  }
  std::cout<<std::endl;
  
  /// sort the sequence
  double* buffer = new double[n];  // we allocate buffer for the merge_sort
  merge_sort(sequence, buffer, n);
  delete[] buffer;  // we deallocate the buffer, as we do not need it anymore
  
  /// print the sorted sequence
  std::cout<<"Sorted sequence: ";
  for (unsigned i=0; i<n; ++i)
    std::cout<<sequence[i]<<"  ";
  std::cout<<std::endl;
  
  delete[] sequence;  // deallocate the memory for the sequence
  return 0;
}
