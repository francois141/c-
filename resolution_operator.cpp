#include <iostream>

int x = 2;

int main() {
    int x = 3;

    std::cout << "Local x : " << x << " global x : " << ::x << std::endl;

    return 0;
}