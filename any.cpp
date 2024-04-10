#include <iostream>
#include <any>

using namespace std;

int main()
{
    std::cout << std::boolalpha;

    any val = make_any<int>(1);
    cout << any_cast<int>(val) << " " << val.type().name() << " " << val.has_value() << endl;

    val = make_any<string>("string");
    cout << any_cast<string>(val) << " " << val.type().name() << " " << val.has_value() << endl;

    val.reset();
    cout << val.type().name()  << " " << val.has_value() << endl;

    try {
        val = "coucou";
        cout << any_cast<string>(val) << endl;
    } catch(bad_any_cast error) {
        cout << "Bad any_cast" << endl;
    }
}