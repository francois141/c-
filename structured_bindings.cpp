#include <iostream>
#include <tuple>

using namespace std;

tuple<int, string, double> getInfo() {
    return make_tuple(25, "John Doe", 100.0);
}

int main() {

    // Structured binding
    auto [age, name, height] = getInfo();

    cout << age << " " << name << " " << height << endl;

    return 0;
}