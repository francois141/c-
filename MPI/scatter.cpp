#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {

    MPI_Init(&argc, &argv);

    int rank, size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int buffer[20];

    if(rank == 0) {
        for(int i = 0; i < 20;i++) buffer[i] = 456;
    }

    int value;
    MPI_Scatter(buffer, 1, MPI_INT, &value, 1, MPI_INT, 0, MPI_COMM_WORLD);

    cout << to_string(value) + "\n";

    MPI_Finalize();

    return 0;
}