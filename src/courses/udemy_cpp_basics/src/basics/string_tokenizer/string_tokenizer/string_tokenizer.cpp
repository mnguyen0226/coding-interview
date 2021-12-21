// string_tokenizer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    std::cout << "String conversion\n";
    char s1[10] = "234";
    char s2[10] = "64.78";
    
    long int x = strtol(s1, NULL, 10); // convert string to long
    cout << x << endl;

    // convert string to float
    float y = strtof(s2, NULL);
    cout << y << endl;

    // string tokenizer
    char name[100]= "minh|nguyen|tran";
    char* token = strtok(name, "|");
    while (token != NULL){
        cout << token << endl;
        token = strtok(NULL, "|"); // reset token
    }
    return 0;
}
