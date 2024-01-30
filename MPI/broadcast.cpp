#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank;
    int size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int value = rank == 0 ? 45 : 0;

    MPI_Bcast(&value, 1, MPI_INT,0, MPI_COMM_WORLD);

    cout << to_string(value) + "\n";

    MPI_Finalize();
    return 0;
}
