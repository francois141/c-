#include <iostream>

using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

// Template functions can be overloaded
template<typename T>
T add(T a, T b, T c) {
    return a + b + c;
}

// Templates can also be overloaded
template<int C, typename T>
T add(T a, T b) {
    return a + b + C;
}

int main() {
    cout << add<>(3,3) << endl;
    cout << add<>(3,3,3) << endl;
    cout << add<1, int>(3,3) << endl;
    return 0;
}