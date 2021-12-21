// string_change_lowercase.cpp : This file contains the 'main' function. Program execution begins and ends there.
// TODO: Write a function that change uppercase string to lowercase string

#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

string toLowerCase(string s) {
    // Declare an iterator
    string::iterator it;
    string new_s = "";
    for (it = s.begin(); it != s.end(); it++) {
        //cout << typeid(*it).name() << endl;
        new_s.push_back(tolower(*it)); // for char, you can't append it
    }
    return new_s;
}

int main()
{
    std::cout << "Hello World!\n";
    string s = "BRUH";

    string lower_s = toLowerCase(s);
    cout << lower_s << endl;

    return 0;
}
