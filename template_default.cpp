#include <iostream>

using namespace std;

// Template can have default values
template <int A = 1, int B = 2>
int add() {
    return A + B;
}

template <int A = 1, int B = A + 1>
int add_second() {
    return A + B;
}

template<typename T, int S = sizeof(T)>
int g() {
    return S;
} 

int main() {
    cout << add() << endl;
    cout << add<2>() << endl;
    cout << add<3,3>() << endl;
    cout << add_second() << endl;
    cout << g<double>() << endl;
    cout << g<int>() << endl;
    return 0;
}