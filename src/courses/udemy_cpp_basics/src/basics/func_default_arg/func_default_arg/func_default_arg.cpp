// func_default_arg.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

// Write a template function that has default arg
int Max(int a, int b, int c = 0) {
    if (a >= b && a >= c) {
        return a;
    }
    else {
        if (b >= c) {
            return b;
        }
        else {
            return c;
        }
    }
}

int main()
{
    std::cout << "Default Arg Do Comparison\n";

    int a = 1;
    int b = 2; 

    cout << Max(1, 2) << endl;

    return 0;
}
