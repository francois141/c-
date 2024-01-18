#include <algorithm>
#include <vector>
#include <iostream>
#include <ranges>   // new header!
#include <string_view>

int main() {
    const std::vector numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto even = [](int i) { return 0 == i % 2; };

    auto rv = std::views::reverse(std::views::drop(std::views::filter(numbers, even), 1));
    for (auto& i : rv)
        std::cout << i << ' ';
    std::cout << std::endl;

    for (int i : std::views::filter(std::views::iota(1, 100), even))
        std::cout << i << ' ';
    std::cout << '\n';

    const std::string text = {"              Hello world"};

    auto transformation = std::views::transform(std::views::drop_while(text, isspace), toupper);
    for(auto e: transformation) {
        std::cout << ((char)e);
    }
    std::cout << std::endl;
}
