// cin_name_string.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
    char name[50];
    cout << "Please enter your name: " << endl;
    cin >> name;
    cout << "Print: " << name << endl;

    cin.ignore(INT_MAX, '\n'); // clear the input buffer. If you use getline()/ note just get(). then no need to use ignore

    cout << "Please try to enter your name again: " << endl;
    cin.getline(name,50); // overwrite
    cout << "Print: " << name << endl;

    cout << "Please try to enter your name again: " << endl;
    cin.getline(name, 50); // overwrite
    cout << "Print: " << name << endl;

    return 0; // end function
}
