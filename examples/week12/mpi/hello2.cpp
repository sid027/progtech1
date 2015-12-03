#include <iostream>
#include <string>
#include <sstream>
#include <mpi.h>

int main(int argc, char** argv) {
    
    MPI_Init(&argc, &argv);
    int num, tot;
    
    MPI_Comm_size(MPI_COMM_WORLD, &tot);
    MPI_Comm_rank(MPI_COMM_WORLD, &num);
    
    if( num == 0 ) { // master
        MPI_Status status;
        int received = 0;
        while( received < tot - 1 ) {
            char txt[100];
            MPI_Recv(txt, 100, MPI_CHAR, MPI_ANY_SOURCE, 99, MPI_COMM_WORLD, &status);
            std::cout << txt << std::endl;
            received++;
        }
    }
    else { // slave
        std::stringstream ss;
        ss << "hello from node " << num;
        MPI_Send(const_cast<char*>(ss.str().c_str()), ss.str().size()+1, MPI_CHAR, 0, 99, MPI_COMM_WORLD);
    }
    
    MPI_Finalize();
}
