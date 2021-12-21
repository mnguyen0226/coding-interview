// string_class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
    std::cout << "String Class" << endl;
    string str = "Hello"; // Declaration and initialization
    cout << str << endl;;

    cout << "Enter a String: " << endl;
    string any = ""; // no fixed size of a string
    getline(cin, any); // just until new line char
    cout << any << endl;

    return 0;
}
