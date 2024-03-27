#include <bits/stdc++.h>

using namespace std;

template <typename... Args> 
constexpr int somme(Args... args) {
    return (... + args);
}

int main() {
    static_assert(somme(1,2,3,4) == 10);
    return 0;
}
