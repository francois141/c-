#include <iostream>
#include <vector>
#include <thread>
#include <mutex>

int x = 0;

std::mutex mtx;

void dummy() {
    for(int i = 0; i < 10000;i++) {
        mtx.lock();
        x++;
        mtx.unlock();
    }
}

void dummy_lock_guard() {
    for(int i = 0; i < 10000;i++) {
        std::lock_guard<std::mutex> lck(mtx);
        x++;
    }
}

int main() {
    std::vector<std::thread> threads;

    const unsigned int nb_threads = 10;

    for(int i = 0;i < nb_threads;i++) {
        threads.push_back(std::thread(dummy_lock_guard));
    }

    for(int i = 0; i < nb_threads;i++) {
        threads[i].join();
    }

    std::cout << x << std::endl;

    return 0;
}

