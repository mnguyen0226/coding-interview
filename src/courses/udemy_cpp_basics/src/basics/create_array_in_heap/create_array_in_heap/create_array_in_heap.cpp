// create_array_in_heap.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
    std::cout << "Create array in the heap\n";

    // Note that if you create int A[5], then array will be created in the stack which you can't modify
    // Thus we create array in the heap with the use of pointer
    int size;

    cout << "Please enter the size of the array: ";
    cin >> size;

    int* p; // create a pointer type int that has the size of 8 bytes
    p = new int[20]; // create an array with size "size" in the heap and let p point to that array
    
    cout << "The size of array in the heap is: " << sizeof(*p) << endl; // return both 4 because that the size of int and there is nothing in the array

    delete[]p;

    // Change the size of the array in the heap. 
    p = new int[40];
    cout << "The size of array in the heap is: " << sizeof(*p) << endl;

    return 0; // End the function
}

