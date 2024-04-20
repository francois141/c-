#include <iostream>

using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}

// Generic type -> typename
// Uses generic type

// Non-type template parameters -> int, enum,...
// Uses concrete value

// Explicit template instantiation
template int add<int>(int,int);

int main() {

    // Deducted argument types
    cout << add(1,1) << endl;

    // Explicit template arguments
    cout << add<int>(1,1) << endl;

    return 0;
}