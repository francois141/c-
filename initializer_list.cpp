#include <bits/stdc++.h>
using namespace std;

class Box {
private:
    int* m_data;
    int m_size;

public:
    Box() {
        m_data = nullptr;
        m_size = 0;
    }

    explicit Box(const std::initializer_list<int> &values) {
        m_data = new int[values.size()];
        m_size = values.size();

        int i = 0;
        for (auto value : values) {
            m_data[i] = value;
            i++;
        }
    }

    ~Box() {
        delete[] m_data;
    }


    int getSize() {
        return m_size;
    }
};

int main() {
    std::initializer_list<int> values = {1,2,3,4,5};

    Box b = Box(values);
    cout << b.getSize() << endl;
}