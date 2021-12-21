#include <iostream>
using namespace std;

// Function just display number
void func(int n)
{
    if (n > 0)
    {
        cout << n << endl;
        func(n - 1);
    }
}

int main()
{
    int x = 3;
    func(x);

    return 0;
}