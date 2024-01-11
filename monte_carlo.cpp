#include <bits/stdc++.h>
#include <atomic>

using namespace std;

void monte_carlo(int runs, atomic<double> &value) {
    double val = 0;
    int idx = 0;
    while(idx ++ < runs) {
        double x = rand() / (double)RAND_MAX;
        double y = rand() / (double)RAND_MAX;
        if(x * x + y * y <= 1.0) {
            val++;
        }
    }

    // Perform compare and swap when done
    while(!value.compare_exchange_strong(reinterpret_cast<double &>(value), value + 4.0 * (val / (runs))));
}

int main() {
    srand(time(NULL));

    atomic<double> value = 0;

    const unsigned int nb_threads = 50;
    vector<thread> threads;
    for(int i = 0; i < nb_threads;i++) {
        threads.push_back(thread(monte_carlo, 1000000, ref<atomic<double>>(value)));
    }

    for(thread &t : threads) {
        t.join();
    }

    cout << fixed << setprecision(15) << value / nb_threads << endl;

    return 0;
}