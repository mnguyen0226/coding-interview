// function_return_by_address.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Challenge: Create a function that can create an array in the heap that can change the size dynamically

#include <iostream>

using namespace std;

int* create_dy_array(int size) {
    int* p = new int[size]; // create a pointer that point to array in the heap
    for (int i = 0; i < size; i++) {
        p[i] = i;
    }
    return p;
}


int main()
{
    std::cout << "Return by Address\n";
    int* arr = create_dy_array(3); // heap memory can be access anywhere in the program

    for (int t = 0; t < 3; t++) {
        cout << arr[t] << " ";
    }
    cout << endl;

    

}
