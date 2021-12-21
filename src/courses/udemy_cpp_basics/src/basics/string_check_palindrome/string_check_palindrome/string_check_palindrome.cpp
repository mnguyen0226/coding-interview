// string_check_palindrome.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Challenge: Check if a given string is palindrome or now

#include <iostream>
#include <string>

using namespace std;

void check_palindrome(string s) {
    // get the reverse and check equality
    string rev_s = "";
    string::reverse_iterator rit;
    for (rit = s.rbegin(); rit != s.rend(); rit++) {
        rev_s.push_back(*rit);
    }

    if (s.compare(rev_s) == 0) {
        cout << "Equal" << endl;
    } else{
        cout << "Not Equal" << endl;
    }
}

int main()
{
    std::cout << "Check string palindrome\n";

    string s1 = "hah";
    check_palindrome(s1);

    string s2 = "Hah";
    check_palindrome(s2);
}
