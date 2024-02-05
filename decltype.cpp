#include <iostream>

struct A {
    double x;
};

A* a;

decltype(a->x) y;

template<typename T, typename U>
auto add(T t, U u) -> decltype(t + u) {
    return t + u;
}

int main() {

    static_assert(std::is_same_v<double, decltype(a->x)>);

    return 0;
}