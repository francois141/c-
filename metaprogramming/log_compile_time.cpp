#include <iostream>

using namespace std;

template<int x>
struct log2_template {
    constexpr static int value = 1 + log2_template<x / 2>::value;
};

template<>
struct log2_template<1> {
    constexpr static int value = 0;
};


int main() {
    static_assert(log2_template<17>::value == 4);
    static_assert(log2_template<16>::value == 4);
    static_assert(log2_template<32>::value == 5);
    return 0;
}