#include <iostream>

using namespace std;

template<int a, int b>
struct gcd {
    constexpr static int value = gcd<b, a%b>::value;
};

template<int a>
struct gcd<a,0> {
    constexpr static int value = a;
};


int main() {
    return gcd<33,11>::value;
}