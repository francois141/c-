#include <iostream>
#include <type_traits>

using namespace std;

class A {
    public:
    virtual void test() = 0;
};

class B: A{
    public:
    void test();
};

int main() {
    // Compile time assertion
    static_assert(1 + 1 == 2, "This compiles");

    // Cpp17, we have assertion without messages
    static_assert(1 == 1);

    // Query properties of types using type traits
    static_assert(is_integral<int>::value);
    static_assert(!is_integral<double>::value);

    // And a more readable version starting from cpp 17
    static_assert(is_integral_v<int>);

    // A few other examples
    static_assert(is_floating_point_v<double>);
    static_assert(is_arithmetic_v<int>);
    static_assert(is_signed_v<int>);
    static_assert(is_unsigned_v<size_t>);
    static_assert(is_void_v<void>);
    static_assert(is_pointer_v<int*>);
    static_assert(is_null_pointer_v<nullptr_t>);
    static_assert(is_reference_v<int&>);
    static_assert(is_array_v<int[]>);
    static_assert(is_function_v<void()>);
    static_assert(is_class_v<A>);
    static_assert(is_abstract_v<A>);
    static_assert(is_polymorphic_v<B>);
    static_assert(is_const_v<const int>);
    static_assert(is_same_v<int,int>);
    static_assert(is_convertible_v<int, float>);

    return 0;
}