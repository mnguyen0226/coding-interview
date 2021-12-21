// pointer_reference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    std::cout << "Pointer Reference\n";

    // Reference is just a way to nick name a variable, however, the nicknamed variable can be used only once.
    int x = 10;
    int& y = x; // must be define when declare

    cout << x << endl;
    cout << y << endl;

    y++;
    cout << x << endl;

    y++;
    cout << x << endl;

    return 0;
}
