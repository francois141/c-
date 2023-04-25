#include <iostream>

class Parent {
    public:
    virtual void print() {
        std::cout << "print from parent" << std::endl;
    }
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
    Parent *p = new Parent();
    print(p);

    Child *c = new Child();
    print(c);

    return 0;
}