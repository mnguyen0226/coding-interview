#include <iostream>
using namespace std;

class Parent
{
public:
    Parent(){}; // constructor
    void func1() { cout << "This is a parent class" << endl; }
};

class Child : public Parent
{
public:
    Child(){}; // constructor
    void func2() { cout << "This is a child class" << endl; }
};

int main()
{
    Parent p;
    Child c;
    p.func1();
    c.func2();
    c.func1();

    return 0;
}