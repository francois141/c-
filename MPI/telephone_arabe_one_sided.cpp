#include <bits/stdc++.h>
#include <mpi.h>

int main(int argc, char **argv) {

    MPI_Init(&argc, &argv);

    int *a;

    int output;

    int rank,size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Alloc_mem(sizeof(int)*100, MPI_INFO_NULL, &a);

    MPI_Window win;

    MPI_Win_create(a, 100*sizeof(int), MPI_INT, MPI_INFO_NULL, MPI_COMM_WORLD, &win);

    if(rank == 0) {
        a[0] = 1234567;
    }


    for(int i = 0; i < size;i++) {
        // Create exposure period
        MPI_Win_fence(0,&win);

        if(rank == (i+1) % size) {
            MPI_Get(&output, 1, MPI_INT, i, 0, 1, MPI_INT, &win);  
            a[0] = output;
        }
    }

    // Closing sync
    MPI_Win_fence(0,&win);

    if(rank == 0) {
        assert(a[0] = 1234567);
    }

    MPI_Free_mem(a);

    MPI_Finalize();


    return 0;
}