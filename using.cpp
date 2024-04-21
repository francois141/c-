#include <iostream>


template<typename T>
struct A {
    T x;
};

using A_int = A<int>;

// This doesn't compile
// typedef A_int2 = A<int>;

int main() {

    return 0;
}