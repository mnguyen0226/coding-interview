// dynamic_allocation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    std::cout << "Dynamic Allocation\n";

    int* p; // stack
    p = new int[5]; // pointer variable p in stack point to heap
    int counter = 1;
    // Store some elements in the heap
    for (int i = 0; i < 5; i++) {
        p[i] = counter;
        counter++;
    }

    cout << "Check the values of arrays in the heap via pointer: " << endl;
    for (int x = 0; x < 5; x++) { // Can't use for each since we have to modify directly and for each just copy
        cout << p[x] << endl;
    }

    // NOTE: if I have p=NULL, then it will no longer point to int[5] which will cost memory leak

    delete[]p;
    p = nullptr;

    cout << "Address of nullptr/Value of p is: " << p << endl;
//    cout << "Value of nullptr is: " << *p << endl; // not exist
    cout << "Address of p is: " << &p << endl;

    return 0;
}

