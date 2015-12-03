/* Programming Techniques for Scientific Simulations, HS 2015
 * Week 11
 */

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

typedef double calc_type;
typedef int size_type;

extern "C" {
    void dsyev_( const char* JOBZ , const char* UPLO, const int* N, double* A, const int* LDA, double* W, 
                 double* WORK, const int* LWORK, int* INFO ) ;
}

inline void print(const std::vector<calc_type>& A, const int n) {
	for (int i=0; i<n; ++i) {
		for (int j=0; j<n; ++j) {
			std::cout << A[i*n+j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
    // parameters of the task
    const calc_type K=1.;
    const calc_type mass=1.;
    const size_type N=16;
    const size_type N_show=(N>16?8:N);
    const size_type size_of_workspace=(N+2)*N+1;
    
    // data structures
    std::vector<calc_type> M(N*N);
    std::vector<calc_type> omega_sq(N);
    std::vector<calc_type> workspace(size_of_workspace);
    
    // fill in the Hamiltonian
    std::fill(M.begin(),M.end(),0.);
    for (size_type n=0; n<N; ++n) {  // diagonal
      M[n*N+n]=2;
    }
    for (size_type n=0; n<N-1; ++n) { // diagonal shifted 1 rows above
      M[n*N+n+1]=-1;
    }
    print(M,N);
    
    size_type info;
    const char task='V', triangle='L';
    dsyev_(&task, &triangle, &N, &(M.front()), &N, &(omega_sq.front()), &(workspace.front()), &size_of_workspace, &info);
    
    if (info!=0) {
        std::cerr<<"An error occured in the dsyev_ function. INFO="<<info<<std::endl;
    } else {
        std::cout<<"Omega  Eigenvector"<<std::endl;
        for (size_type i=0; i<N_show; ++i) {
            std::cout<<std::sqrt(K/mass*omega_sq[i])<<"  [";
            for (size_type j=0; j<N; ++j) {
                std::cout<<M[i*N+j]<<(j==N-1?"":", ");
            }
            std::cout<<"]"<<std::endl;
        }
    }
    
    return 0;
}
