#include <iostream>

using namespace std;

int main()
{
    for (int i = 100; i <= 500; i++)
    {
        int num = i;

        int first = num / 100;
        num = num % 100;

        int second = num / 10;
        int third = num % 10;

        if (first * first * first + second * second * second + third * third * third == i)
        {
            cout << "Number: " << i << endl;
        }
    }

    return 0;
}