#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank;
    int size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    MPI_Win win;

    int *window_buffer;
    MPI_Alloc_mem(sizeof(int), MPI_INFO_NULL, &window_buffer);
    window_buffer[0] = 0;

    MPI_Win_create(window_buffer, sizeof(int), sizeof(int), MPI_INFO_NULL, MPI_COMM_WORLD, &win);

    MPI_Win_fence(0, win);

    int val = 2;
    int tmp;

    // Compare and swap will always succeed
    MPI_Compare_and_swap(&val, window_buffer,&tmp, MPI_INT, 0, 0, win);

    MPI_Win_fence(0, win);

    string message = to_string(rank) + " " + to_string(window_buffer[0]) + " " + to_string(tmp) + "\n";
    cout << message;

    MPI_Win_free(&win);
    MPI_Free_mem(window_buffer);
    MPI_Finalize();

    return 0;
}
