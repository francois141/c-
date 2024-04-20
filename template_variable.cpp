#include <iostream>

using namespace std;

// Variable an also be templated
template<typename T>
constexpr T e { static_cast<T>(2.71) };

int main() {
    cout << e<double> << endl;
    cout << e<int> << endl;
    return 0;
}