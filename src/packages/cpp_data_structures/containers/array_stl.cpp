/*Illustration of array container stl*/

#include <iostream>
#include <array>

using namespace std;

int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // prints out all element in array
    for (auto iter = begin(A); iter != end(A); ++iter)
    {
        cout << *iter << " ";
    }
    cout << endl;
}