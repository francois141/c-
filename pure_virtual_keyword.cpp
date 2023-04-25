#include <iostream>

class Parent {
    public:
    virtual void print() = 0;
};

class Child : public Parent {
    void print() {
        std::cout << "print from child" << std::endl;
    }
};


void print(Parent *p) {
    p->print();
}

int main() {

    Child *c = new Child();
    print(c);

    return 0;
}