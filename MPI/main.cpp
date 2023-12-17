#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank;
    int size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if(rank == 1){
        int b[1];
        b[0] = 888;
        MPI_Send(b, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }
    if(rank == 0) {
        int b[1];
        MPI_Recv(b,1, MPI_INT, 1, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << b[0] << endl;
    }

    MPI_Finalize();

    return 0;
}
