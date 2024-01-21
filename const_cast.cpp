#include <iostream>

using namespace std;

int main() {
    const int value = 1;
    int *value2;
    value2 = const_cast<int*>(&value);
    (*value2)++;
    cout << *value2 << endl;
    cout << value << endl;
    return 0;
}