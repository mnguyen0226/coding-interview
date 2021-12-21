// base_class_pointer_derive_class_object.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Base {

public:
    // Constructors
    Base() {};

    void func1() { cout << "Func 1 Base" << endl; };
};

class Derived :public Base {
public:
    Derived(): Base() {}; // Constructor inheritant
    void func2()
    {
        cout << "Func 2 Derived" << endl;
    };
};

int main()
{
    std::cout << "Hello World!\n";

    // Call a Base Class as Derived class since both class has functions of base class
    Base* d = new Derived();
    d->func1();

    // Derived* d = new Base(); // Can't call Derived class as Based class since all function of Derived class does not have in Based

    return 0;
}
