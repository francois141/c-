#include <iostream>

using namespace std;

template<auto X, auto Y>
void test() {
    
}

int main() {
    test<1,'a'>(); // Works in cpp 17
    return 0;
}