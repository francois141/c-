#include <iostream>

using namespace std;

class sample {
public:
    explicit sample(int x) {
        cout << "Value " << x << endl;
    }
};


int main() {
    sample s1 = static_cast<sample>(3);
    sample s2 = static_cast<sample>(4);
    return 0;
}