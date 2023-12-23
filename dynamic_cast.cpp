#include <iostream>

using namespace std;

class Parent {
    virtual void print() {
        cout << "parent" << endl;
    }
};

class Child : public Parent {
};

class Child2 : public Parent {
};

int main() {
    Parent *p = new Child();
    Child *c = dynamic_cast<Child*>(p);
    cout << c << endl;

    Child2 *c2 = dynamic_cast<Child2*>(p);
    cout << c2 << endl;

    return 0;
}