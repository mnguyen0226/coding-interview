// string_iterator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;

int main()
{
    std::cout << "String Iterator\n"; // iterator is used to traverse through string
    string s = "Minh Nguyen";

    // Task: Traverse forth and back of a given string
    string::iterator it; // access the address of each character in the array
    for (it = s.begin(); it != s.end(); it++) {
        cout << *it << endl;
    }
    cout << endl;

    string::reverse_iterator rit;
    for (rit = s.rbegin(); rit != s.rend(); rit++) {
        cout << *rit << endl;
    }

    cout << endl;

    return 0;
}

