#include <iostream>

using namespace std;

int main()
{
    int A[] = {10, 12, 20, 30, 25, 40, 32, 31, 35, 50, 60};
    int copy_A[10];
    int j = 0;
    for (int i = 3; i <= 8; i++)
    {
        copy_A[j] = A[i];
        j++;
    }
    return 0;
}