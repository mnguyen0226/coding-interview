#include <iostream>

using namespace std;

int main()
{
    int num;
    cout << "Please enter a 5-digit number: ";
    cin >> num;

    int first = num / 10000;
    num = num % 10000;

    int second = num / 1000;
    num = num % 1000;

    int third = num / 100;
    num = num % 100;

    int fourth = num / 10;
    int fifth = num % 10;

    int result = first + fourth;
    cout << "The result is: " << result << endl;

    return 0;
}