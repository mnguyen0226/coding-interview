// function_pass_by_address_reference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;;

// pass by address
void swap1(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// pass by reference 
void swap2(int& a, int& b) {
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int main()
{
    std::cout << "Swap 1\n";
    int a = 1;
    int b = 2;
    swap1(&a, &b);
    cout << a << " " << b << endl;

    swap2(a, b);
    cout << a << " " << b << endl;

    return 0;
}