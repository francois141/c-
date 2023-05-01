#include <iostream>
#include <vector>
#include <thread>
#include <atomic>

std::atomic_int x = std::atomic<int>(0);


void dummy() {
    for(int i = 0; i < 10000;i++) {
        x++;
    }
}


int main() {
    std::vector<std::thread> threads;

    const unsigned int nb_threads = 10;

    for(int i = 0;i < nb_threads;i++) {
        threads.push_back(std::thread(dummy));
    }

    for(int i = 0; i < nb_threads;i++) {
        threads[i].join();
    }

    std::cout << x << std::endl;

    return 0;
}

