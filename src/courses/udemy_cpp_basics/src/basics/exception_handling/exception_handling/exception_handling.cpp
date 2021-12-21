// exception_handling.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    int x = 10, y = 0, z;
    try {
        if (y == 0) { throw 1; } // throw will go to catch
        z = x / y;
        cout << z << endl;
    }
    catch (int e) {
        cout << "Division by zero " << e << endl;
    }

    cout << "Bye" << endl; // this show that the program will catch instead of being terminated

    return 0;
}
