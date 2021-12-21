// pointer_arithmetics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    std::cout << "Pointer Arithmetics\n";

    // There are 5 pointer arithmetics only
    int A[] = { 1,2,3,4,5,6,7,8,9,10 }; // stack

    int* p; // stack
    p = A; // point to the first element of the array. This is because array is also pointer

    cout << "First element of the array is: " << *p << endl;

    // Arithmetic 1:
    p++;
    cout << *p << endl;

    // Arithmetic 2:
    p--;
    cout << *p << endl;

    // Arithmetic 3:
    p += 2;
    cout << *p << endl;

    // Arithmetic 4:
    p -= 2;
    cout << *p << endl;

    // Arithmetic 5:
    int* q = &A[5];

    int d = q - p;

    cout << d << endl;


    return 0;
}
