#include <bits/stdc++.h>

struct S {
    int val1;
    int val2;
};

int f1(std::shared_ptr<S> s) {
    int n = 100000;
    while(n--) s->val1++;
    return 0;
}

int f2(std::shared_ptr<S> s) {
    int n = 100000;
    while(n--) s->val2++;
    return 0;
}

int main() {
    std::shared_ptr<S> object = std::make_shared<S>();

    std::thread t1(f1, object);
    std::thread t2(f2, object);

    t1.join();
    t2.join();

    std::cout << object->val1 << " " << object->val2 << std::endl;

    return 0;
}