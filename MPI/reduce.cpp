#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank;
    int size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    // Simple reduction - computes sum
    {
        int buffer = rank;
        int output = 0;

        MPI_Reduce(&buffer, &output, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

        if(rank == 0) cout << output << endl;
    }

    // Reduction with double - computes sum
    {
        double buffer = rank + 0.1;
        double output = 0.0;

        MPI_Reduce(&buffer, &output, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

        if(rank == 0) cout << output << endl;
    }

    // Reduction with binary or (|)
    {
        int buffer = rank;
        int output = 0;

        MPI_Reduce(&buffer, &output, 1, MPI_INT, MPI_BOR, 0, MPI_COMM_WORLD);

        if(rank == 0) cout << output << endl;
    }

    MPI_Finalize();
    return 0;
}
