// string_get_email.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Challenge: get the username and email address

#include <iostream>
#include <string>
using namespace std;

int main()
{
    std::cout << "Find Email\n";

    string email = "mnguyen0226@gmail.com";
    string username = "";

    // Use find to find the @   
    // Use substr to find the email
    
    int pos = email.find('@');
    username = email.substr(0, pos);

    cout << username;
  
    return 0;
}
