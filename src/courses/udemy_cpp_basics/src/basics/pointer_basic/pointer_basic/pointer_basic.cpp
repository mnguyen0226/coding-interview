// pointer_basic.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    std::cout << "Pointer\n";

    int a = 10; // 2 bits
    int* p; // 8 bytes
    p = &a;

    cout << a << endl;
    cout << &a << endl;
    cout << p << endl;
    cout << &p << endl;
    cout << *p << endl;

    return 0; // end of function
}
