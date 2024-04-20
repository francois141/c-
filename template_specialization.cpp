#include <iostream>

using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

template<>
float add(float a, float b) {
    cout << "float function" << endl;
    return a + b;
}

int main() {
    cout << add<>(3,3) << endl;
    cout << add<>(3.f,3.f) << endl;
    return 0;
}