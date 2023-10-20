#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank;
    int size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int b[1];

    if(rank == 0) {
        b[0] = 123456;
        MPI_Send(b,1,MPI_INT, 1, 0, MPI_COMM_WORLD);
        MPI_Recv(b, 1, MPI_INT, size-1, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << b[0] << "\n";
    } else {
        MPI_Recv(b, 1, MPI_INT, rank-1, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        b[0]++;
        MPI_Send(b,1, MPI_INT, (rank+1) % size, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}
