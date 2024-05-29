#include <iostream>

using namespace std;

template <class T>
class Base {
public:
    Base() = default;
    void Print()  {
        static_cast<T*>(this)->Print();
    }
};

class Derived : public Base<Derived> {
public:
    void Print() {
        std::cout << "children!" << std::endl;
    }
};

class Derived2 : public Base<Derived2> {
public:
    void Print() {
        std::cout << "children 2!" << std::endl;
    }
};

template <typename T>
void Printer(Base<T> *basic) {
    basic->Print();
}

int main() {
    auto current = new Derived();
    Printer(current);
}