#include <bits/stdc++.h>

using namespace std;

class myInteger {

public:

    myInteger(int x) {
        val = x;
    }

    operator string() {
        cout << "String output : " << val << endl;
        return to_string(this->val);
    }

    operator int() {
        return val;
    }
private:
    int val;
};

int main() {
    float f = 3.14;

    int f2 = static_cast<int>(f);
    cout << f2 << "\n";

    string s = static_cast<string>(myInteger(4));
    cout << s << endl;

    int i = static_cast<int>(myInteger(5));
    cout << i << endl;

    return 0;
}