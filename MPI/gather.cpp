#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {

    MPI_Init(&argc, &argv);

    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int value = rank;
    int buffer[20];

    MPI_Gather(&value, 1, MPI_INT, buffer, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        for(int i = 0; i < 20;i++) cout << buffer[i] << endl;
    }

    MPI_Finalize();

    return 0;
}