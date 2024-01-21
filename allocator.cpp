#include <iostream>
#include <vector>
#include <memory>

template <typename T>
struct CustomAllocator {
    using value_type = T;
    CustomAllocator() noexcept {}

    template<typename U>
    CustomAllocator(const CustomAllocator<U>&) noexcept {}

    T* allocate(std::size_t n) {
        auto p = std::malloc(n * sizeof(T));
        if(p != nullptr) {
            std::cout << "Successful allocation" << std::endl;
            return static_cast<T*>(p);
        }
        throw std::bad_alloc();
    }

    void deallocate(T *p, std::size_t) noexcept {
        std::free(p);
    }
};

template <typename T, typename U>
bool operator==(const CustomAllocator<T>&, const CustomAllocator<U>&) noexcept {
return true;
}

template <typename T, typename U>
bool operator!=(const CustomAllocator<T>&, const CustomAllocator<U>&) noexcept {
return false;
}

int main() {
    std::vector<int, CustomAllocator<int>> vec;
    vec.push_back(42);
    return 0;
}