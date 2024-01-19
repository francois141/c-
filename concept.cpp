#include <iostream>

template <typename T>
concept IntegralValue = std::is_integral_v<T>;

template <typename T>
concept isNotPointer = not std::is_pointer_v<T>;

template <IntegralValue T>
T add(T a, T b) {
    return a + b;
}

template <typename T> requires std::is_signed_v<T> and isNotPointer<T>
T func(T param) {
    return param;
}

template<isNotPointer T>
T mult(T a, T b) {
    return a * b;
}

int main() {
    std::cout << "Sum: " << add(3, 4) << std::endl;

    signed int val = 1;
    std::cout << "Sum: " << func(val) << std::endl;

    float val2 = 1.0;
    std::cout << "Sum: " << func(val2) << std::endl;

    float val3 = 1.0;
    std::cout << "Mult: " << mult(val3, val3) << std::endl;

    return 0;
}