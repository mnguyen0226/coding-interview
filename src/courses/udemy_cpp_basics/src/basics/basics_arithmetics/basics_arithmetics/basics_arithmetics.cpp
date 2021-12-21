// basics_arithmetics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    int a, b, c;
    a = 10;
    b = 2;
    c = a++ * b; // a = 11, b = 2, c = 20 = assign to a then multiply to b
    //c = ++a * b; // a = 11, b = 2, c = 22

    cout << a << " " << b << " " << c << endl;

    return 0;
}

