#include <iostream>

using namespace std;

struct A {
    int x;
    constexpr A(int x1) : x{x1} {};
};


// This allowed in cpp 20
template<A a>
int g() {
    return a.x;
}


int main() {
    g<A{5}>(); 
    return 0;
}