#include <iostream>
#include <functional>

using namespace std;

void func(int x, int y)
{
    std::cout<<"x: "<<x<<" y: "<<y<<"\n";
}


class MyClass
{
public:
    int func(int x)
    {
        std::cout<<"x: "<<x<<"\n";
        return x*x;
    }
};

int main()
{
    MyClass object;

    auto function = std::bind(&MyClass::func, object, std::placeholders::_1);
    cout << function(10) << endl;

    auto second = std::bind(func, 5, std::placeholders::_1);
    second(1);

    std::bind(func, 5, std::placeholders::_1)(143);

    return 0;
}