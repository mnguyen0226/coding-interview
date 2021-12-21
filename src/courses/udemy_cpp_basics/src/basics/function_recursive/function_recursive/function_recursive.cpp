// function_recursive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void func(int n) {
    if (n > 0) {
        cout << n << endl;
        func(n - 1);
    }
}

int main()
{
    std::cout << "Hello World!\n";
    int x = 5;
    func(x);

    return 0;
}
