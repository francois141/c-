#include <iostream>

template <typename T>
concept IntegralValue = std::is_integral<T>::value;

template <IntegralValue T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
requires std::is_signed<T>::value
T func(T param) {
    return param;
}


int main() {
    std::cout << "Sum: " << add(3, 4) << std::endl;

    signed int val = 1;
    std::cout << "Sum: " << func(val) << std::endl;

    float val2 = 1.0;
    std::cout << "Sum: " << func(val2) << std::endl;

    return 0;
}