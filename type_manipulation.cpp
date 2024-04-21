#include <iostream>
#include <type_traits>

using namespace std;

using U = make_unsigned<int>::type;
using S = make_signed<unsigned int>::type;

int main() {
    
    // Change signed <--> unsigned
    static_assert(is_same<U,unsigned int>::value);
    static_assert(is_same<S,int>::value);

    // Remote & add pointers
    static_assert(is_same<int,remove_pointer<int*>::type>::value);
    static_assert(is_same<int*,add_pointer<int>::type>::value);

    // Remove & add l value reference
    static_assert(is_same<int, remove_reference_t<int&>>::value);
    static_assert(is_same<int&,add_lvalue_reference_t<int>>::value);

    // Remove and add const
    static_assert(is_same<const int, add_const_t<int>>::value);
    static_assert(is_same<int, remove_const_t<const int>>::value);

    // Conditional
    static_assert(is_same<conditional_t<true, int,double>, int>::value);
    static_assert(is_same<conditional_t<false, int,double>, double>::value);

    return 0;
}