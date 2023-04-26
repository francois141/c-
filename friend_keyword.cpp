#include <iostream>

using namespace std;

class Test {
    private:
    string data = "data";

    friend std::ostream& operator<<(std::ostream& out, const Test& t);
};

std::ostream& operator<<(std::ostream& out, const Test& t) {
    return out << t.data << std::endl;
}

int main() {
    Test t;
    std::cout << t;
    
    return 0;
}