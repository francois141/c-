#include <iostream>

using namespace std;


template<typename = void>
void g() {}


int main() {
    g(); // Generates g only if we call it
    return 0;
}