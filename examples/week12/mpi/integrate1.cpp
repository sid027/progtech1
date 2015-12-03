#include <iostream>
#include <mpi.h>
#include <cmath>

double integrate (double (*f)(double), double a, double b, unsigned int n) {
    double dx=(b-a)/n;
    double sum=0.5*(f(a)+f(b));
    for (int i=1;i<n;++i)
        sum += f(a+dx*i);
    return sum*dx;
}

int main(int argc, char** argv) {
    
    // setup
    
    MPI_Init(&argc, &argv);
    int num, total;
    MPI_Comm_rank(MPI_COMM_WORLD,&num);
    MPI_Comm_size(MPI_COMM_WORLD,&total);
    double a=0.;
    double b=1.;
    int steps=1024*1024*256;
    
    // do one interval
    
    double interval=(b-a)/total;
    double start=a+interval*num;
    double end=start+interval;
    double partial=integrate(sin,start,end,steps/total);
    
    // sum up intervals
    
    double sum=0.;
    MPI_Allreduce(&partial,&sum,1,MPI_DOUBLE,MPI_SUM,MPI_COMM_WORLD);
    
    // print and finish
    
    if (num==0) // only one prints
        std::cout << "The integral is " << sum << "\n";
    MPI_Finalize();
}
