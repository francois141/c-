#include <iostream>

using namespace std;

// Enforces compile time constraint
template <int X, int Y>
consteval int add() {
    return X + Y;
}

int main() {
    cout << add<1,2>() << endl;
}