#include <iostream>
#include <future>
#include <unistd.h>

using namespace std;

int cnt;

int getValue() {
    for(int i = 0; i < 100000;i++) cnt++;
    return cnt;
}

int main() {

    // Async launch policy
    {
        cnt = 0;
        cout << "Async launch policy : " << endl;
        future<int> test = async(launch::async, getValue);
        usleep(200);
        cout << cnt << endl;
        cout << test.get() << endl;
    }

    // Deferred launch policy
    {
        cnt = 0;
        cout << "Defered launch policy : " << endl;
        future<int> test = async(launch::deferred, getValue);
        usleep(200);
        cout << cnt << endl;
        cout << test.get() << endl;
    }

    return 0;
}