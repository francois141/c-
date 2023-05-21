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

std::unique_ptr<MyClass> printValueUnique(std::unique_ptr<MyClass> pointer) {
    std::cout << "In function print value unique : ";
    std::cout << pointer->str << std::endl;

    return pointer;
}

void printValueShared(std::shared_ptr<MyClass> pointer) {
    std::cout << "Use count of shared smart pointer : " << pointer.use_count() << std::endl;
    std::cout << "In function print value shared : ";
    std::cout << pointer->str << std::endl;
}


int main() {
    
    std::cout << "Test with unique pointers" << std::endl;

    std::unique_ptr<MyClass> pointer = std::make_unique<MyClass>();

    pointer = printValueUnique(std::move(pointer));

    std::unique_ptr<MyClass> pointer2 = std::move(pointer);

    std::cout << pointer2->str << std::endl;

    pointer2.reset();

    std::cout << "Test with shared pointers" << std::endl;

    std::shared_ptr<MyClass> pointerShared = std::make_shared<MyClass>();

    printValueShared(pointerShared);

    return 0;
}