#include <iostream>
#include <string>
#include <mpi.h>

int main(int argc, char** argv) {
    MPI_Status status;
    int num;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD,&num);
    double d=num;
    int tag=99;
    if(num==0) {
        MPI_Ssend(&d,1,MPI_DOUBLE,1,tag,MPI_COMM_WORLD);
        MPI_Recv(&d,1,MPI_DOUBLE,1,tag,MPI_COMM_WORLD,&status);
    }
    else {
        MPI_Recv(&d,1,MPI_DOUBLE,0,tag,MPI_COMM_WORLD,&status);
        MPI_Ssend(&d,1,MPI_DOUBLE,0,tag,MPI_COMM_WORLD);
    }
    MPI_Finalize();
}
