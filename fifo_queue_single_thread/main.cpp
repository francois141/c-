#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <atomic>

#include <assert.h>

template<typename T>
class Fifo
{
public:
    explicit Fifo() : Fifo(128) {

    }

    explicit Fifo(std::size_t capacity): capacity_(capacity), pushCursor(0), popCursor(0) {
        ring = new T[capacity_];
    }

    Fifo(const Fifo<T> &other) : capacity_(other.capacity_) {
        pushCursor.store(other.pushCursor.load(), std::memory_order_seq_cst);
        popCursor.store(other.popCursor.load(), std::memory_order_seq_cst);

        ring = new T[capacity_];

        for(int i = 0; i < capacity_;i++) {
            ring[i] = other.ring[i];
        }
    }

    ~Fifo() {
        delete ring;
    }

    std::size_t capacity() const { return capacity_; }
    std::size_t size() const { return pushCursor - popCursor; }

    bool empty() const { return size() == 0;}
    bool full() const {return size() == capacity(); }

    bool push(T const& value) {
        if(full()) {
            return false;
        }

        ring[pushCursor % capacity_] = value;
        pushCursor++;

        return true;
    }

    bool pop_blocking(T&value) {
        while(empty()) {}
        return pop(value);
    }

    bool pop(T& value) {
        if(empty()) {
            return false;
        }

        value = ring[popCursor % capacity_];
        ring[popCursor % capacity_].~T();

        popCursor++;

        return true;
    }

    T* ring;
private:
    std::size_t capacity_;

    std::atomic<std::size_t> pushCursor;
    std::atomic<std::size_t> popCursor;
};

bool run_benchmark(int nb_times = 10000, int capacity = 127) {

    std::vector<Fifo<int>> values(nb_times, Fifo<int>(capacity));

    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < nb_times;i++) {
        std::thread producer([&values](int idx) -> void {
            for(int j = 0; j < values[idx].capacity();j++) { values[idx].push(j); }
        }, 1);

        std::thread consumer([&values](int idx) -> void {
            int out;
            for(int j = 0; j < values[idx].capacity();j++) { values[idx].pop_blocking(out); assert(out == j); }
        }, 1);

        producer.join();
        consumer.join();
    }

    auto end = std::chrono::high_resolution_clock::now();

    double time_taken = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count() * 1e-9;
    std::cout << "Time taken by program is : " << std::fixed << time_taken << " sec" << std::endl;

    return true;
}


int main() {

    run_benchmark();

    return 0;
}