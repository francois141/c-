#include <iostream>

int main() {

    int myAge = 15;

    try {
        if(myAge < 18) {
            throw myAge;
        }
    } catch(int myAge) {
        std::cout << "You are too young : " << myAge << std::endl;
    }

    try {
        throw 100;
    } catch(...) {
        std::cout << "Catched an exception" << std::endl;
    }
 
    return 0;
}