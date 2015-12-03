#include <iostream>
#include <cmath>
#include <mpi.h>

double integrate (double (*f)(double), double a, double b, unsigned int n) {
    double dx=(b-a)/n;
    double sum=0.5*(f(a)+f(b));
    for (int i=1;i<n;++i)
        sum += f(a+dx*i);
    return sum*dx;
}

struct segment_info {
    segment_info() {}
    segment_info(double a_, double b_, unsigned int n_)
    : a(a_), b(b_), n(n_)
    {}
    
    double a;
    double b;
    unsigned int n;
};


void master()
{
    MPI_Status status;
    int total;
    MPI_Comm_size(MPI_COMM_WORLD,&total);
    --total; // master does not do work
    
    double a=0.;
    double b=1.;
    int steps=1024*1024*256;
    double interval=(b-a)/total;
    
    // send requests
    for (int i=0;i<total;++i) {
        segment_info seg(a+i*interval, a+(i+1)*interval,steps/total);
        MPI_Send(&seg,sizeof(segment_info),MPI_BYTE,i+1,0,MPI_COMM_WORLD);
    }
    
    // receive answers
    double sum=0.;
    double partial=0.;
    for (int i=0;i<total;++i) {
        MPI_Recv(&partial,1,MPI_DOUBLE,i+1,1,MPI_COMM_WORLD,&status);
        sum += partial;
    }
    std::cout << "The integral is " << sum << "\n";
}

void slave()
{
    MPI_Status status;
    segment_info seg;
    MPI_Recv(&seg,sizeof(segment_info),MPI_BYTE,0,0,MPI_COMM_WORLD,&status);
    double partial=integrate(sin,seg.a,seg.b,seg.n);
    MPI_Send(&partial,1,MPI_DOUBLE,0,1,MPI_COMM_WORLD);
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);
    int num;
    MPI_Comm_rank(MPI_COMM_WORLD,&num);
    
    if (num==0)
        master();
    else
        slave();
    
    MPI_Finalize();
}
