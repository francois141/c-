#include <iostream>
#include <thread>

void dummy() {
    std::cout << "Dummy function output" << std::endl;
}

class dummy_class {
    public: 
        void operator() (int v){
            std::cout << "Dummy callable class" << std::endl;
        }
};

auto dummy_lambda = []() {
    std::cout << "Dummy lambda function" << std::endl;
};

int main() {
    std::thread t1(dummy);
    std::thread t2(dummy_class(),0);
    std::thread t3(dummy_lambda);

    t1.join();
    t2.join();
    t3.join();

    return 0;
}

