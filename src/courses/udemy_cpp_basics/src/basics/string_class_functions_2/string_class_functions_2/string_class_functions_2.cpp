// string_class_functions_2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
int main()
{
    std::cout << "String Class Function 2!\n";
    string name = "Minh Nguyen";
    
    // Append
    name.append(" Yes"); // this will increase the length and the capacity
    cout << "Append: " << name << endl; 

    // Insert string at given index
    name.insert(3, " random ");
    cout << "Insert: " << name << endl;

    // Replace position 3, total 5 alphabet
    name.replace(3, 5, "b"); 
    cout << "Replace: " << name << endl;

    // Erase
    name.clear();
    cout << "Clear: " << name << endl;

    name = "Minh Nguyen";
    
    // Push back
    name.push_back('z');
    cout << "Push back: " << name << endl;

    // Pop back
    name.pop_back();
    cout << "Pop back: " << name << endl;

    // Swap
    string s = "bruh";
    name.swap(s);
    cout << "Swap: " << name << endl;
    cout << s << endl;


    string s1 = "Hello";
    // Copy - not strcpy
    char s2[10];
    s1.copy(s2, s1.length());
    s2[5] = '\0'; // have to do this to stop gabage char copy
    cout << "Copy: " << s2 << endl;

    // Find
    cout << "Find: " << s1.find("o") << endl; // Return a position

    // RFind
    cout << "Rfind: " << s1.rfind("Bruh") << endl; // Not found will return -1 or largest number depends on the compiler

    // Find first of
    cout << "Find First Of: " << s1.find_first_of('l') << endl; // position of first time find the char

    // Find last of
    cout << "Find Last Of: " << s1.find_last_of('l') << endl; // position of last time find the char

    // Sub String - get the word/char that you want in a substring
    string sub_s;
    sub_s = s1.substr(3, 4); // at position 3, get 4 letters. In this case, it will return "lo" althought we request 4 char
    cout << "Substring: " << sub_s << endl;

    // Compare
    string h_1 = "Hello";
    string h_2 = "Hello";
    string h_3 = "hello";
    cout << "Compare: " << h_1.compare(h_2) << endl; // return 0 = equal
    cout << "Compare: " << h_1.compare(h_3) << endl; // return -1 = h_1 < h_3

    return 0;
}
