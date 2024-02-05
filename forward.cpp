#include <iostream>
#include <utility>

using namespace std;

void overloaded(const int& x) { cout << "[lvalue] ";}
void overloaded(int&& x) { cout << "[rvalue] ";}

template <typename T>
void function(T&& x) {
    overloaded(x);
    overloaded(std::forward<T>(x));
    cout << "\n";
}

int main() {
    int a;
    function(a);
    function(1);
}