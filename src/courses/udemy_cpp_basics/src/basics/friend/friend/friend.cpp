// friend.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class F;
class Test{
private: int a;
protected:int b;
public:int c;

      friend F;
};

class F {
public:
    Test t;

    void func() {
        t.c;
        t.a;
        t.b;
    }
};

int main()
{
    std::cout << "Hello World!\n";
}
