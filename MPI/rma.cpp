#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank;
    int size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int window_buffer = 0;
    if(rank == 1) window_buffer = 12345;

    MPI_Win win;

    MPI_Win_create(&window_buffer, sizeof(int), sizeof(int), MPI_INFO_NULL, MPI_COMM_WORLD, &win);
    MPI_Win_fence(0, win);

    window_buffer = 34;

    MPI_Barrier(MPI_COMM_WORLD);

    if(rank == 1) {
        int val;
        MPI_Get(&val, 1, MPI_INT, 1, 0,1, MPI_INT, win);
        cout << val << endl;
    }

    MPI_Win_free(&win);

    MPI_Finalize();

    return 0;
}
