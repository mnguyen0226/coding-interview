// string_function.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    std::cout << "String Function\n";
    char s[50] = "Minh Nguyen";
    cout << strlen(s) << endl; // does not count the "0\"

    char n[100]; // this is not correct
    cout << sizeof(n) << endl; // 4?
    cout << "Enter a String" << endl;
    cin.getline(n, 100);
    cout << n << endl;

    // Concatenate strings
    char s1[20] = "Good";
    char s2[10] = " Morning";
    strcat_s(s1, s2);
    cout << s1 << endl;

    // String Copy
    char des[50] = "";
    strcpy_s(des, s1); 
    cout << "COPY: " << des << endl;


    // Substring 
    char main_s[50] = "Minh Nguyen";
    char sub_s[60] = "guy";
    cout << strstr(main_s, sub_s) << endl; // give the rest of the string

    if (strstr(main_s, sub_s) != NULL) {
        cout << strstr(main_s, sub_s) << endl; // give the rest of the string
    }
    else {
        cout << "Not Found" << endl;
    }


    return 0;
}

