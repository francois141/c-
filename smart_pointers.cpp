#include <iostream>
#include <memory>

class MyClass{
public:
    std::string str = "Hello from class\n";
    MyClass(){
        std::cout << "Constructor invoked" << std::endl;
    }
    ~MyClass(){
        std::cout << "Destructor invoked" << std::endl;
    }
};

std::unique_ptr<MyClass> printValue(std::unique_ptr<MyClass> pointer) {
    std::cout << "In function print value : ";
    std::cout << pointer->str << std::endl;

    return pointer;
}

int main() {
    std::unique_ptr<MyClass> pointer = std::make_unique<MyClass>();

    pointer = printValue(std::move(pointer));

    std::unique_ptr<MyClass> pointer2 = std::move(pointer);

    std::cout << pointer2->str << std::endl;

    return 0;
}