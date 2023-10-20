#include <bits/stdc++.h>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv) {
    MPI_Init(&argc, &argv);

    int rank;
    int size;

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    assert(size == 4); // Otherwise output is wrong

    vector<int> a(10000);

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> dis(-1.0, 1.0);

    generate(a.begin(), a.end(), [&dis, &gen]()->double {
        double x = dis(gen);
        double y = dis(gen);
        return (x*x + y*y <= 1.0) ? 1.0 : 0.0;
    });

    double value = accumulate(a.begin(), a.end(), 0.0) / a.size();

    double output;
    MPI_Reduce(&value, &output, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0) {
        cout << output << endl;
    }

    MPI_Finalize();
    return 0;
}
