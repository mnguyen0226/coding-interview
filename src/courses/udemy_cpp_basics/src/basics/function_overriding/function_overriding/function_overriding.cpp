// function_overriding.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Base{
public:
    void display() {
        cout << "Display of Base" << endl;
    }
};

class Derived :public Base {
public:
    void display() {
        cout << "Display of Derived" << endl;
    }
};

int main()
{
    std::cout << "Hello World!\n";
    Derived d;
    d.display();

    return 0;
}

