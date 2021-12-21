// poly_virtual.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Base{
public:
    virtual void out() {
        cout << "BASE" << endl;
    };
};

class Derived :public Base {
public:
    void out() {
        cout << "DERIVED" << endl;
    };
};

int main()
{
    std::cout << "Hello World!\n";

    // Called a Derived class as Base
    Base* b = new Derived();
    b->out(); // Since called by pointer

    Base* b2 = new Base();
    b2->out();

    return 0;
}
