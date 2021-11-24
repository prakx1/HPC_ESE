#include <stdio.h>
#include "mpi.h"

int main(int argc, char **argv) {
    int size, rank;
    int localdata;
    int result;
    const int root = 0;

    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    //Prepare local data
    localdata = rank*2+1;
    printf("[Process %d]: has local data %d\n", rank, localdata);
    
    //MPI_Reduce(sendbuf, recvbuf, count, MPI_INT, MPI_SUM, root, MPI_COMM_WORLD);
    MPI_Reduce(&localdata, &result, 1, MPI_INT, MPI_SUM, root, MPI_COMM_WORLD);

    if (rank == root) {
        printf("[root Process %d]: has the result: %d", rank,result);
        printf("\n");
    }

    MPI_Finalize();
    return 0;
}
