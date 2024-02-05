#include <bits/stdc++.h>

using namespace std;

std::mutex l;

typedef struct node {
    node *prev;
    int blocked;
} node;

node *lck = new node;

void lock(node *qn) {
    qn->blocked = 1;

    l.lock();
    qn->prev = lck;
    lck = qn;
    l.unlock();

    while(qn->prev->blocked){}
}

void unlock(node *qn) {
    delete qn->prev;
    qn->blocked = 0;
}

int cnt = 0;

void compute() {
    for(int i = 0; i < 1000000;i++) {
        node *n = new node;
        lock(n);
        cnt++;
        unlock(n);
    }
}

int main() {

    lck->blocked = 0;

    thread t1(compute);
    thread t2(compute);
    thread t3(compute);
    thread t4(compute);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << cnt << endl;
    return 0;
}