// How to set array as parameter
// Pass in the pointer to array and number of element in the array
// Array only pass by address

#include <iostream>

using namespace std;

// Array passed by address not value
void func(int A[], int n)
{ // pointer is 8 bytes int is 4 bytes
    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " " << endl;
    }
}

int * create_arr(int size){
    int *p;
    p = new int[size]; // dynamically create an array

    for(int i = 0; i < size; i++){
        p[i] = i+1;
    }

    return p;
}

int main()
{
    int A[] = {2, 4, 6, 8, 10};
    int n = 5;

    // print out values in the array
    func(A, n);

    // create array dynamically
    int *ptr, sz = 5;
    ptr = create_arr(sz);

    // test print out
    func(ptr, sz);

    return 0;
}
